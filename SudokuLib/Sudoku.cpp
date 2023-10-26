/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"
#include "Sparty.h"
#include "Scoreboard.h"
#include "Digit.h"
#include "Given.h"
#include "Xray.h"
#include "MessageBoard.h"
#include <wx/graphics.h>
#include "LevelLoad.h"
#include "SolveLoad.h"

using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    wxString level1 = "levels/level1.xml";
    LevelLoad level(level1, this);

    mPixelWidth = level.PixelWidth();
    mPixelHeight = level.PixelHeight();

    mScoreboard = make_shared<Scoreboard>(this);
    mScoreboard->StartClock();
    //shared_ptr<Item> board = make_shared<MessageBoard>(this);
    //board->SetLocation(494, 375);
    //mItems.push_back(board);
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
        item->Draw(graphics, mPixelWidth, mPixelHeight);
    }
    mScoreboard->Draw(graphics, mPixelWidth, mPixelHeight);

    graphics->PopState();
}
void Sudoku::SetLocation(wxMouseEvent &event)
{

    int xLoc = (event.GetX() - mXOffset) / mScale;
    int yLoc = (event.GetY() - mYOffset) / mScale;

 //Convert to virtual pixels and set Location
    mSparty->SetLocation(xLoc, yLoc);
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
    mScoreboard->StartClock();
}

bool Sudoku::Eater(Item *eater)
{
    for(auto other : mItems)
    {
        // Do not compare to ourselves
        if (other.get() == eater) {
            continue;
        }

        if (other->HitTest((int)eater->GetX(), (int)eater->GetY()) && other->IsDigit())
        {
            auto loc = find(begin(mItems), end(mItems), other);
            if (loc != end(mItems))
            {
                mItems.erase(loc);
            }

            return true;
        }

    }
    return false;
}

void Sudoku::Solve(wxString levelToSolve)
{
    SolveLoad solve(levelToSolve, this);
}
