/**
 * @file Item.cpp
 * @author Lillian Yanke
 */

#include "pch.h"
#include "Item.h"
#include "Sudoku.h"
using namespace std;

/**
 * Constructor
 * @param sudoku
 * @param filename
 */
Item::Item(Sudoku *sudoku, const std::wstring &filename) : mSudoku(sudoku)
{
    mItemImage = make_unique<wxImage> (filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);

}

/**
 * Draw an item
 * @param dc Device context to draw on
 */
void Item::Draw(wxDC *dc)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    dc->DrawBitmap(*mItemBitmap,
                   int(GetX() - wid / 2),
                   int(GetY() - hit / 2));
}