/**
 * @file Xray.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "Xray.h"
#include <wx/graphics.h>
using namespace std;

const wstring XrayImageName = L"images/xray.png";

Xray::Xray(Sudoku* sudoku) : Item(sudoku, XrayImageName) {
    mItemImage = make_unique<wxImage>(XrayImageName, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}


void Xray::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    double x = 30; // Left
    double y = height - hit; // Bottom

    // Draw the image at the calculated position
    graphics->DrawBitmap(*mItemBitmap, x, y, wid, hit);
}