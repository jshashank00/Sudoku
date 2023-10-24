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
#include "Pumpkin.h"
#include "Cauldron.h"
#include "MessageBoard.h"
#include <wx/graphics.h>
#include "LevelLoad.h"

using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{

    mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);
    wxString level1 = "levels/level1.xml";
    LevelLoad level(level1, this);
    shared_ptr<Item> scoreboard = make_shared<Scoreboard>(this);
    mItems.push_back(scoreboard);
    shared_ptr<Item> board = make_shared<MessageBoard>(this);
    board->SetLocation(494, 375);
    mItems.push_back(board);
    //wxString background = "images/" + level.GetBackground();
    //mBackground = make_unique<wxBitmap>(background, wxBITMAP_TYPE_ANY);
    // Create a sparty
    // This creates a shared pointer to sparty
    /**
    mSparty = make_shared<Sparty>(this);
    shared_ptr<Item> scoreboard = make_shared<Scoreboard>(this);
    shared_ptr<Item> digit = make_shared<Digit>(this);
    shared_ptr<Item> given = make_shared<Given>(this);
    shared_ptr<Item> xray = make_shared<Xray>(this);
    shared_ptr<Item> pumpkin = make_shared<Pumpkin>(this);
    shared_ptr<Item> cauldron = make_shared<Cauldron>(this);
    shared_ptr<Item> board = make_shared<MessageBoard>(this);

    // Set the location
    mSparty->SetLocation(100, 100);
    digit->SetLocation(200, 100);
    given->SetLocation(270, 175 );
    xray->SetLocation(50, 0);
    pumpkin->SetLocation(204, 176);
    cauldron->SetLocation(220, 215);
    board->SetLocation(494, 375);

    // Add to the list
    mItems.push_back(scoreboard);
    mItems.push_back(digit);
    mItems.push_back(given);
    mItems.push_back(xray);
    mItems.push_back(pumpkin);
    mItems.push_back(cauldron);
    mItems.push_back(board);
    mItems.push_back(mSparty);
     */
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

    // Determine the size of the playing area in virtual pixels (up to you)
    int pixelWidth = 988;
    int pixelHeight = 750;

    // Calculate the scaling factors
    double scaleX = double(width) / double(pixelWidth);
    double scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    // Calculate the offsets for centering the content
    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = (height - pixelHeight * mScale) / 2.0;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    // Draw the background image
    if (mBackground) {
        graphics->DrawBitmap(*mBackground, 0, 0, pixelWidth, pixelHeight);
    }

    for(auto item : mItems)
    {
        item->Draw(graphics, pixelWidth, pixelHeight);
    }

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
    //item->SetLocation(100, 200);
    mItems.push_back(item);
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

void Sudoku::ChooseLevel(wxString levelToLoad)
{
    LevelLoad level(levelToLoad, this);
}