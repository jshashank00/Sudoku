/**
 * @file Sparty.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Sparty.h"
#include <wx/graphics.h>

using namespace std;

/// Character speed in pixels per second
const double MaxSpeed = 400.00;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;

/// Sparty filename
const wstring SpartyImageName = L"images/sparty-1.png";

/// Sparty filename
const wstring SpartyImageMouthName = L"images/sparty-2.png";

/**
 * Constructor
 * @param sudoku The sudoku game we are in
 * @param filename Filename for the image we use
 */
Sparty::Sparty(Sudoku *sudoku) :
    Item(sudoku, SpartyImageName)
{
    mItemImage = make_unique<wxImage> (SpartyImageMouthName, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    Item::Draw(graphics, 100, 100);
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    graphics->DrawBitmap(*mItemBitmap,
                   int(GetX() - wid / 2),
                   int(GetY() - hit / 2), wid, hit);
}