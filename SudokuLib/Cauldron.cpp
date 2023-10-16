/**
 * @file Cauldron.cpp
 * @author jbrown
 */

#include "pch.h"
#include "Cauldron.h"
#include <wx/graphics.h>
using namespace std;

/// Cauldron filename
const wstring CauldronImageName = L"images/cauldron.png";


Cauldron::Cauldron(Sudoku* sudoku) : Item(sudoku, CauldronImageName) {
    mItemImage = make_unique<wxImage>(CauldronImageName, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}


void Cauldron::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    double x = 800; // Left
    double y = height - hit; // Bottom

    // Draw the image at the calculated position
    graphics->DrawBitmap(*mItemBitmap, x, y, wid, hit);
}