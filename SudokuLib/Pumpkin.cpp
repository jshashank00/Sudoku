/**
 * @file Pumpkin.cpp
 * @author jbrown
 */
#include "pch.h"
#include "Pumpkin.h"
#include <wx/graphics.h>
using namespace std;

/// Cauldron filename
const wstring PumpkinImageName = L"images/pumpkin.png";

/**
 * pumpkin constructor
 * @param sudoku The current sudoku game
 */
Pumpkin::Pumpkin(Sudoku* sudoku) : Item(sudoku, PumpkinImageName) {
    mItemImage = make_unique<wxImage>(PumpkinImageName, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Draw the pumpkin
 * @param graphics
 * @param width width of area to draw in
 * @param height height of area to draw in
 */
void Pumpkin::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    double x = 600; // Left
    double y = height - hit; // Bottom

    // Draw the image at the calculated position
    graphics->DrawBitmap(*mItemBitmap, x, y, wid, hit);
}