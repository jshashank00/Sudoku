/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"
#include "Sparty.h"
#include "Scoreboard.h"
#include "Number.h"
#include "Digit.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);

    // Create a sparty
    // This creates a shared pointer to sparty
    shared_ptr<Item> sparty = make_shared<Sparty>(this);
    shared_ptr<Item> scoreboard = make_shared<Scoreboard>(this);
    shared_ptr<Number> num = make_shared<Digit>(this);

    // Set the location
    sparty->SetLocation(100, 100);
    num->SetLocation(200, 100);

    // Add to the list
    mItems.push_back(sparty);
    mItems.push_back(scoreboard);
    mItems.push_back(num);
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


/**
* Add an item to the game
 * @param item New item to add
*/
void Sudoku::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(100, 200);
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