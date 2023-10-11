/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    mBackground = new wxBitmap(L"images/background.png", wxBITMAP_TYPE_ANY);

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
//    dc->SetFont(font);
//    dc->SetTextForeground(wxColour(0, 64, 0));
//    dc->DrawText(L"Under the Sea!", 10, 10);
}

