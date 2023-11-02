/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"
#include "Sparty.h"
#include "Scoreboard.h"
//#include "MessageBoard.h"
#include "Digit.h"
#include "Given.h"
#include "Xray.h"
#include <wx/graphics.h>
#include "LevelLoad.h"
#include <wx/string.h>
#include <iostream>
#include <string>
#include "DigitVisitor.h"
#include "IsContainerVisitor.h"
#include "GivenVisitor.h"
#include "XrayFinder.h"
#include <cstdlib>
#include <thread>

using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    wxString level0 = "levels/level0.xml";
    wxString level1 = "levels/level1.xml";
    wxString level2 = "levels/level2.xml";
    wxString level3 = "levels/level3.xml";
    this->ChooseLevel(level1);
    mMessageBoardVisible = true;
}

/**
 * Getter for mSparty
 * @return mSparty
 */
std::shared_ptr<Item> Sudoku::GetSparty()
{
    return mSparty;
}


/**
 * Getter for mItems
 * @return mItems
 */
const std::vector<std::shared_ptr<Item>>& Sudoku::GetItems() const
{
    return mItems;
}

/**  Test an x,y click location to see if it clicked
* on some item in the game.
* @param x X location
* @param y Y location
* @return Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Sudoku::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }
    return  nullptr;
}

/**
 * Draw the game
 * @param graphics Device context to draw on
 * @param width of image
 * @param height of image
 */
void Sudoku::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mElapsedTime += elapsed;

    // Calculate the scaling factors
    double scaleX = double(width) / double(mPixelWidth);
    double scaleY = double(height) / double(mPixelHeight);
    mScale = std::min(scaleX, scaleY);

    // Calculate the offsets for centering the content
    mXOffset = (width - mPixelWidth * mScale) / 2.0;
    mYOffset = (height - mPixelHeight * mScale) / 2.0;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    // Draw the background image
    //if (mBackground) {
    //    graphics->DrawBitmap(*mBackground, 0, 0 ,mPixelWidth, mPixelHeight);
    //}

    for(auto item : mItems)
    {
        if (!item->IsInContainer())
        {
            item->Draw(graphics, mPixelWidth, mPixelHeight);
        }
    }

    mMessageBoard->Draw(graphics, mPixelWidth, mPixelHeight, mLevelMessage);
    mScoreboard->Draw(graphics, mPixelWidth, mPixelHeight);
    if (mGameOver)
    {
        mFullMessage->Draw(graphics, mPixelWidth, mPixelHeight);
    }

    if (mComplete)
    {
        mLevelCompleteMessage->Draw(graphics, mPixelWidth, mPixelHeight);
    }

    if (mCompleteIncorrectly)
    {
        mIncorrectMessage->Draw(graphics, mPixelWidth, mPixelHeight);
    }

    if (mBoxFull)
    {
        mFullMessage->DrawTakenSquare(graphics, mPixelWidth, mPixelHeight);
    }
    graphics->PopState();
}

/**
 * Set the location of sparty
 * @param event mouse event
 */
void Sudoku::SetLocation(wxMouseEvent &event)
{

    int xLoc = (event.GetX() - mXOffset) / mScale;
    int yLoc = (event.GetY() - mYOffset) / mScale;

    if (xLoc >= 48 && xLoc < mPixelWidth && yLoc >= 0 && yLoc < mPixelHeight)
    {

        //Convert to virtual pixels and set Location
        mSparty->SetLocation(xLoc, yLoc);
    }
}

/**
* Add an item to the game
 * @param item New item to add
*/
void Sudoku::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
* Add an item to the game
 * @param item New item to add
*/
void Sudoku::AddFront(std::shared_ptr<Item> item)
{
    mItems.insert(mItems.begin(), item);
}

/**
*  Clear the level data.
*  Deletes all known items in the game.
*/
void Sudoku::Clear()
{
    mItems.clear();
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Sudoku::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}

/**
 * Set the game sparty
 * @param sparty Game sparty
 */
void Sudoku::SetSparty(shared_ptr<Item> sparty)
{
    mSparty = sparty;
}
//void Sudoku::SetFullMsg(shared_ptr<Item> FullMessage)
//{
//    mFullMessage = FullMessage;
//}
//void Sudoku::SetXray(shared_ptr<Item> xray)
//{
//    mXray = xray;
//}


/**
 * Set the pixel height
 * @param height pixel height
 */
void Sudoku::SetPixelHeight(int height)
{
    mPixelHeight = height;
}
/**
 * Set the pixel width
 * @param wid pixel width
 */
void Sudoku::SetPixelWidth(int wid)
{
    mPixelWidth = wid;
}

/**
 * Choose the level to be loaded
 * @param levelToLoad level that needs to be loaded
 */
void Sudoku::ChooseLevel(wxString levelToLoad)
{
    LevelLoad level(levelToLoad, this);

    mPixelWidth = level.PixelWidth();
    mPixelHeight = level.PixelHeight();
    mComplete = false;
    mCompleteIncorrectly = false;
    mColumn = level.GetColumn();
    mRow = level.GetRow();
    mTileHeight = level.GetTileHeight();

    mSolution = level.Solution();

    mLevelMessage = level.GetLevel();

    if (levelToLoad.IsSameAs(L"levels/level0.xml"))
    {
        mNextLevel = L"levels/level1.xml";
        mSameLevel = L"levels/level0.xml";
    }

    if (levelToLoad.IsSameAs(L"levels/level1.xml"))
    {
        mNextLevel = L"levels/level2.xml";
        mSameLevel = L"levels/level1.xml";
    }

    if (levelToLoad.IsSameAs(L"levels/level2.xml"))
    {
        mNextLevel = L"levels/level3.xml";
        mSameLevel = L"levels/level2.xml";
    }

    if (levelToLoad.IsSameAs(L"levels/level3.xml"))
    {
        mNextLevel = L"levels/level1.xml";
        mSameLevel = L"levels/level3.xml";
    }

    mMessageBoard = make_shared<MessageBoard>(this);
    //mMessageBoard->MessageTimer();
    //mFullMessage = make_shared<FullMessage>(this);
    mScoreboard = make_shared<Scoreboard>(this);
    //mScoreboard->StartClock();
    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());

    mMessageBoard->MessageTimer();
    mScoreboard->StartClock();

    mGridXLeft = mColumn * mTileHeight - (mTileHeight/2);
    mGridXRight = mColumn * mTileHeight - (mTileHeight/2) + (mTileHeight * 9);
    mGridYTop = (mRow + 1) * mTileHeight - mTileHeight - (mTileHeight/2);
    mGridYBot = (mRow + 1) * mTileHeight - mTileHeight - (mTileHeight/2) + (mTileHeight * 9);

    std::string solution = std::string(mSolution.ToStdString());

    mVectorSolution.clear();

    for (int i = 0; i < solution.length(); i++)
    {
        if (isdigit(solution[i]))
        {
            int val = solution[i] - '0';  // Convert char to int
            mVectorSolution.push_back(val);
        }
    }
}

/**
 * Eat a number
 * @param eater Sparty
 */
void Sudoku::Eater(Item *eater)
{

    // find the x ray
    XrayFinder xrayVisitor;
    this->Accept(&xrayVisitor);
    Xray * xray = xrayVisitor.GetXray();
//    std::vector<std::shared_ptr<Item>> xrayItems = xray->GetXrayItems();

    for(auto other : mItems)
    {
        // Do not compare to ourselves
        if (other.get() == eater) {
            continue;
        }

        DigitVisitor visitor;
        other->Accept(&visitor);
        if (other->HitTest((int)eater->GetX(), (int)eater->GetY()) && visitor.IsDigit() && !other->IsInContainer() && !other->IsInXray())
        {
            if (xray->AddItem(other)) //add digit to xray items
            {
                auto loc = find(begin(mItems), end(mItems), other);
                if(loc != end(mItems))
                {
                    double xrayXMin = xray->GetX() + 10;
                    double xrayYMin = xray->GetY() - 10;
                    // Calculate the Xray's width and height
                    double xrayWidth = xray->GetWidth() - 20;
                    double xrayHeight = xray->GetHeight() - 20;

                    double digitHeight = other->GetHeight() / 2;
                    double digitWidth = other -> GetWidth() / 2;

                    std::uniform_real_distribution<> distribution(xrayXMin, xrayWidth);
                    std::uniform_real_distribution<> distribution2(xrayYMin, (xrayHeight +xrayYMin - digitHeight));
                    mLocX = distribution(this->GetRandom());
                    mLocY = distribution2(this->GetRandom());
                    for (auto i: xray->GetItems()){
                       if  ((i->GetX()  - mLocX) <= 5){
                           mLocX = mLocX + 5;
                       }

                        if  ((i->GetY()  - mLocY) <= 5){
                            mLocY = mLocY + 5;
                        }
                    }
                    other->SetLocation(mLocX, mLocY);

                }
            }
        }

    }
}

/**
 * Headbutt a container
 * @param sparty Sparty
 */
void Sudoku::HeadbuttContainer(Item *sparty)
{
    for(auto other : mItems)
    {
        // Do not compare to ourselves
        if (other.get() == sparty)
        {
            continue;
        }

        IsContainerVisitor visitor;
        other->Accept(&visitor);
        if (other->ContainerHitTest((int)sparty->GetX(), (int)sparty->GetY()) && visitor.IsContainer())
        {
            // find container
            // get container list of items
            // go through items and change their member variable to !IsInContainer
            // delete items from Container list
            // update items to random place on board

            Container * container = visitor.GetContainer();
            for (auto item: container->GetContainedItems())
            {
                int randomY = (rand() % 150 + 100);
                int randomX = rand() % 201 + (-100);

                int x = 0;
                int y = 0;
                item->SetInContainer(false);
                x = item->GetX() + randomX;
                y = item->GetY() - randomY;
                item->SetLocation(x, y);

            }
            container->Clear();
        }

    }
}

/**
 * Solve a level
 * @param levelToSolve the level we are solving
 */
void Sudoku::Solve(wxString levelToSolve)
{

    int x = mColumn * mTileHeight;
    int y = (mRow+1) * mTileHeight - mTileHeight;

    int original_x = x;
    int count = 0;

    DigitVisitor digit_visitor;
    this->Accept(&digit_visitor);
    int stop_here = digit_visitor.GetDigitCount();
    int stop_count = 0;

    for (int i = 0; i < mVectorSolution.size(); i++)
    {
        if (stop_count == stop_here)
        {
            break;
        }
        else
        {
            if (!TakenSquare(x, y))
            {
                for (auto item : mItems)
                {
                    DigitVisitor visitor1;
                    item->Accept(&visitor1);

                    if (!(item->GetX() > mGridXLeft && item->GetX() < mGridXRight && item->GetY() > mGridYTop
                        && item->GetY() < mGridYBot))
                    {
                        if(visitor1.IsDigit())
                        {
                            if(visitor1.GetValue() == mVectorSolution[i] && !item->IsInContainer() && !item->IsInXray())
                            {
                                item->SetLocation(x, y);
                                stop_count++;
                                break;
                            }

                        }
                    }
                }
                x += mTileHeight;
                count += 1;
                if(count == 9)
                {
                    count = 0;
                    y += mTileHeight;
                    x = original_x;
                }
            }
            else
            {
                x += mTileHeight;
                count += 1;
                if (count == 9)
                {
                    count = 0;
                    y += mTileHeight;
                    x = original_x;
                }
            }
        }
    }
}

/**
 * Check the grid for the solution
 */
void Sudoku::CheckSolution()
{
    std::vector<int> currentBoard = GetAllDigitsInGrid();
    if (mVectorSolution == currentBoard)
    {
        mComplete = true;
        mLevelCompleteMessage = make_shared<LevelCompleteMessage>(this);
        mLevelCompleteMessage->MessageTimer();
        mScoreboard->StopClock();
    }
    if (mVectorSolution != currentBoard && mVectorSolution.size() == currentBoard.size())
    {
        mCompleteIncorrectly = true;
        mIncorrectMessage = make_shared<IncorrectMessage>(this);
        mIncorrectMessage->MessageTimer();
    }
}

/**
     * setter for game over bool
     * @param over true if game over
     */
void Sudoku::SetGameOver(bool over)
{
    mGameOver = over;
    mFullMessage = make_shared<FullMessage>(this);
    mFullMessage->MessageTimer();
}


/**
 * Get the digits in the grid currently
 * @return all the digits currently in the grid
 */
std::vector<int> Sudoku::GetAllDigitsInGrid()
{
    std::vector<int> allDigits;

    for(int row = 0; row < 9; row++) //9x9 Sudoku grid
    {

        for(int col = 0; col < 9; col++)
        {
            int center_x = mGridXLeft + (col * mTileHeight) + (mTileHeight / 2);
            int center_y = mGridYTop + (row * mTileHeight) + (mTileHeight / 2);

            for(auto item : mItems)
            {
                DigitVisitor digitVisitor;
                item->Accept(&digitVisitor);

                GivenVisitor givenVisitor;
                item->Accept(&givenVisitor);

                if(item->GetX() > mGridXLeft && item->GetX() < mGridXRight
                    && item->GetY() > mGridYTop && item->GetY() < mGridYBot)
                {

                    if(item->GetX() == center_x && item->GetY() == center_y)
                    {
                        if(digitVisitor.IsDigit())
                        {
                            allDigits.push_back(digitVisitor.GetValue());
                        }
                        else if(givenVisitor.IsGiven())
                        {
                            allDigits.push_back(givenVisitor.GetValue());
                        }
                    }
                }
            }
        }
    }
    return allDigits;
}


/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Sudoku::Accept(ItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}

/**
 * Test if a square is already taken
 * @param x location of where we want to put it
 * @param y location of where we want to put it
 * @return true if taken
 */
bool Sudoku::TakenSquare(int x, int y)
{
    for (auto item : mItems)
    {
        DigitVisitor digit_visitor;
        item->Accept(&digit_visitor);
        GivenVisitor given_visitor;
        item->Accept(&given_visitor);
        if (given_visitor.IsGiven() || digit_visitor.IsDigit())
        {
            if (item->GetX() == x && item->GetY() == y)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * Move a digit from the xray
 * @param digit digit to be moved
 */
void Sudoku::MoveDigit(int digit)
{
    // find the x ray
    XrayFinder xrayVisitor;
    this->Accept(&xrayVisitor);
    Xray * xray = xrayVisitor.GetXray();
    //mFullMessage->SetXray(xray);

    int center_x = mSparty->GetX();
    int center_y = mSparty->GetY();
    int x = mSparty->GetX();
    int y = mSparty->GetY();
    bool in_grid = false;

    if (x > mGridXLeft && x < mGridXRight && y > mGridYTop && y < mGridYBot) //check if it's in the sudoku grid
    {
        in_grid = true;
        int row = (y - mGridYTop ) / mTileHeight;
        int col = (x - mGridXLeft) / mTileHeight;
        center_x = (mGridXLeft + (col * mTileHeight) + mTileHeight/2);
        center_y = (mGridYTop  + (row * mTileHeight) + mTileHeight/2);
    }

    for (auto item : xray->GetItems())
    {
        DigitVisitor visitor;
        item->Accept(&visitor);
        if(visitor.GetValue() == digit)
        {
            if (in_grid && TakenSquare(center_x, center_y))
            {
                // Add message that
                mBoxFull = true;
                break;
            }
            else
            {
                item->SetLocation(center_x, center_y);
                //item->SetLocation(1200, 528);
                xray->RemoveDigit(item);
                item->SetInXray(false);
                break;
            }
        }

    }
}

/**
 * Set message board flag to know if sparty can move or not
 * @param isVisible
 */
void Sudoku::SetMessageBoardVisible(bool isVisible)
{
    mMessageBoardVisible = isVisible;
}

/**
 * getter for mMessageBoardVisible
 * @return
 */
bool Sudoku::IsMessageBoardVisible() const
{
    return mMessageBoardVisible;
}

/**
 * Reveal a square on the grid
 */
void Sudoku::RevealSquare(int x, int y)
{
//    int x = mSparty->GetX();
//    int y = mSparty->GetY();
    int top_left_center_x = mColumn * mTileHeight;
    int top_left_center_y = (mRow+1) * mTileHeight - mTileHeight;
    if (x > mGridXLeft && x < mGridXRight && y > mGridYTop && y < mGridYBot) //check if it's in the sudoku grid
    {
        int row = (y - mGridYTop ) / mTileHeight;
        int col = (x - mGridXLeft) / mTileHeight;
        int center_x = (mGridXLeft + (col * mTileHeight) + mTileHeight/2);
        int center_y = (mGridYTop  + (row * mTileHeight) + mTileHeight/2);
        int index = (((center_y - top_left_center_y)/mTileHeight) * 9) + ((center_x - top_left_center_x)/mTileHeight);
        int find_value = mVectorSolution[index];

        if (!TakenSquare(center_x, center_y))
        {

            for (auto item : mItems)
            {
                DigitVisitor visitor1;
                item->Accept(&visitor1);

                if (!(item->GetX() > mGridXLeft && item->GetX() < mGridXRight && item->GetY() > mGridYTop
                    && item->GetY() < mGridYBot))
                {

                    if(visitor1.IsDigit())
                    {
                        if(visitor1.GetValue() == find_value && !item->IsInContainer() && !item->IsInXray())
                        {
                            item->SetLocation(center_x, center_y);
                            mItems.push_back(item);
                            auto loc = find(begin(mItems), end(mItems), item);
                            if(loc != end(mItems))
                            {
                                mItems.erase(loc);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}