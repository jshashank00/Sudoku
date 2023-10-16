/**
 * @file Given.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Given.h"
#include <wx/graphics.h>

using namespace std;

const std::wstring GivenImageName = L"images/0b.png";

Given::Given(Sudoku *sudoku) :
    Item(sudoku, GivenImageName)
{
    mGivenImage = make_unique<wxImage> (GivenImageName, wxBITMAP_TYPE_ANY);
    mGivenBitmap = make_unique<wxBitmap>(*mGivenImage);
}

void Given::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    //Item::Draw(graphics, width, height);
    double wid = mGivenBitmap->GetWidth();
    double hit = mGivenBitmap->GetHeight();
    graphics->DrawBitmap(*mGivenBitmap,
                         int(GetX() - wid / 2),
                         int(GetY() - hit / 2), 48, 48);
}