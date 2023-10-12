/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"
using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);
}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Sudoku::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    for(auto item : mItems)
    {
        item->Draw(dc);
    }
//    dc->SetFont(font);
//    dc->SetTextForeground(wxColour(0, 64, 0));
//    dc->DrawText(L"Under the Sea!", 10, 10);
}

/**
* Add an item to the aquarium
 * @param item New item to add
*/
void Sudoku::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(100, 200);
    mItems.push_back(item);
}