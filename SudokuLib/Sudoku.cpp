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
    LevelLoad level(level1, this);

    mPixelWidth = level.PixelWidth();
    mPixelHeight = level.PixelHeight();

//    mColumn = level.Column();
//    mRow = level.Row();
    mSolution = level.Solution();

    mMessageBoard = make_shared<MessageBoard>(this);
    mMessageBoard->MessageTimer();

    mScoreboard = make_shared<Scoreboard>(this);
    mScoreboard->StartClock();
    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());

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
 * @param dc The device context to draw on
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

    //wxString levelMessage;
    mMessageBoard->Draw(graphics, mPixelWidth, mPixelHeight);
    mScoreboard->Draw(graphics, mPixelWidth, mPixelHeight);

    graphics->PopState();
}

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
*
* Deletes all known items in the game.
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

void Sudoku::SetSparty(shared_ptr<Item> sparty)
{
    mSparty = sparty;
}
//void Sudoku::SetXray(shared_ptr<Item> xray)
//{
//    mXray = xray;
//}

void Sudoku::SetPixelHeight(int height)
{
    mPixelHeight = height;
}

void Sudoku::SetPixelWidth(int wid)
{
    mPixelWidth = wid;
}

void Sudoku::ChooseLevel(wxString levelToLoad)
{
    LevelLoad level(levelToLoad, this);
    mMessageBoard->MessageTimer();
    mScoreboard->StartClock();
}

bool Sudoku::Eater(Item *eater)
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
                    //mItems.erase(loc);
                }

                if(other)
                {
                    //Draw item in xray
                }
                return true;
            }
        }

    }
    return false;
}

bool Sudoku::HeadbuttContainer(Item *sparty)
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
//        if (visitor.IsContainer()) {
//            other->ContainerHitTest((int)sparty->GetX(), (int)sparty->GetY());
//        }


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

//                container->GetContainedItems().erase(container->GetContainedItems().begin());
            }
            container->Clear();
            return true;
        }

    }
    return false;
}

void Sudoku::Solve(wxString levelToSolve)
{
    std::vector<int> vector_solution;
    std::string solution = std::string(mSolution.ToStdString());

    for (int i = 0; i < solution.length(); i++)
    {
        if (isdigit(solution[i]))
        {
            int val = solution[i] - '0';  // Convert char to int
            vector_solution.push_back(val);
        }
    }

    int x;
    int y;
    int original_x;
    int count = 0;
    int stop_count = 0;

    for (auto item : mItems)
    {
        GivenVisitor visitor2;
        item->Accept(&visitor2);
        if (visitor2.IsGiven())
        {
            x = item->GetX();
            y = item->GetY();
            original_x = x;
            break;
        }
    }

    for (int i = 0; i < vector_solution.size(); i++)
    {
        if (stop_count == 53)
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

                    if (visitor1.IsDigit())
                    {
                        if (visitor1.GetValue() == vector_solution[i])
                        {
                            item->SetLocation(x, y);
                            stop_count++;
                            mItems.push_back(item);
                            auto loc = find(begin(mItems), end(mItems), item);
                            if(loc != end(mItems))
                            {
                                mItems.erase(loc);
                            }
                            x += 48;
                            count += 1;
                            if (count == 9)
                            {
                                count = 0;
                                y += 48;
                                x = original_x;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                x += 48;
                count += 1;
                if (count == 9)
                {
                    count = 0;
                    y += 48;
                    x = original_x;
                }
            }
        }
    }
//    wxFont font = wxFont(wxSize(60, 60), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
//    std::shared_ptr<wxGraphicsContext> graphics;
//    graphics->SetFont(font, *wxGREEN); // Set the text color to green
//    wxString levelMessage = "Level Complete!";
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
 * @param item digit we want to place
 * @param x location of where we want to put it
 * @param y location of where we want to put it
 */
bool Sudoku::TakenSquare(int x, int y)
{
    for (auto item : mItems)
    {
        GivenVisitor visitor2;
        item->Accept(&visitor2);
        if (visitor2.IsGiven())
        {
            if (item->GetX() == x && item->GetY() == y)
            {
                return true;
            }
        }
    }
    return false;
}

void Sudoku::MoveDigit(int digit, int x, int y)
{
    // find the x ray
    XrayFinder xrayVisitor;
    this->Accept(&xrayVisitor);
    Xray * xray = xrayVisitor.GetXray();

    int row = (y - 120) / 48;
    int col = (x - 168) / 48;
    int center_x = 168 + col * 48 + 24;
    int center_y = 120 + row * 48 + 24;

    for (auto item : xray->GetItems())
    {
        DigitVisitor visitor;
        item->Accept(&visitor);
        if(visitor.IsDigit())
        {
            if(visitor.GetValue() == digit)
            {
                if(!TakenSquare(center_x, center_y))
                {
                    item->SetLocation(center_x, center_y);
                    xray->RemoveDigit(item);
                    item->SetInXray(false);
                    break;
                }
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