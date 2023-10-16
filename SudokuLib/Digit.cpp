/**
 * @file Digit.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Digit.h"
#include <wx/graphics.h>

using namespace std;

const std::wstring DigitImageName = L"images/0b.png";

Digit::Digit(Sudoku *sudoku) :
    Item(sudoku, DigitImageName)
{
    mNumberImage = make_unique<wxImage> (DigitImageName, wxBITMAP_TYPE_ANY);
    mNumberBitmap = make_unique<wxBitmap>(*mNumberImage);
}

void Digit::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //Item::Draw(graphics, width, height);
    double wid = mNumberBitmap->GetWidth();
    double hit = mNumberBitmap->GetHeight();
    graphics->DrawBitmap(*mNumberBitmap,
                         int(GetX() - wid / 2),
                         int(GetY() - hit / 2), 50, 50);
}