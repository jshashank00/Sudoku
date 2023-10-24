/**
 * @file Item.cpp
 * @author Lillian Yanke
 */

#include "pch.h"
#include "Item.h"
#include "Sudoku.h"
#include "Declaration.h"
#include <wx/graphics.h>
using namespace std;

/**
 * Constructor
 * @param sudoku
 * @param filename
 */
Item::Item(Sudoku *sudoku, const std::wstring &filename) : mSudoku(sudoku)
{
    //mItemImage = make_unique<wxImage> (filename, wxBITMAP_TYPE_ANY);
    //mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

void Item::SetImage(const wxString &filename)
{
    mItemImage = make_unique<wxImage> (filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}


Item::Item(Sudoku *sudoku) : mSudoku(sudoku)
{

}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::HitTest(int x, int y)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to theimage top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
//    return !mItemImage->IsTransparent((int)testX, (int)testY);
    return true;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Item::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode)//, shared_ptr<Declaration> decNode)
{
    //mID = node->GetAttribute(L"id", L"0");
    itemNode->GetAttribute(L"col", L"0").ToDouble(&mCol);
    itemNode->GetAttribute(L"row", L"0").ToDouble(&mRow);
    decNode->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    decNode->GetAttribute(L"height", L"0").ToDouble(&mHeight);
    mX = (mCol) * 48;
    mY = (((mRow)-1) * 48);
}

/**
 * Draw an item
 * @param dc Device context to draw on
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    graphics->DrawBitmap(*mItemBitmap,
                         mX,
                         mY, mWidth, mHeight);
}