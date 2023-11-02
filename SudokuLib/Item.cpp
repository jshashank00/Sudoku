/**
 * @file Item.cpp
 * @author Lillian Yanke
 */

#include "pch.h"
#include "Item.h"
#include "Sudoku.h"
#include <wx/graphics.h>
using namespace std;

/**
 * Item Constructor
 * @param sudoku Game we are in
 */
Item::Item(Sudoku *sudoku) : mSudoku(sudoku)
{
    mIsInContainer = false;
}

/**
 * Item Constructor
 * @param sudoku Game we are in
 * @param filename image file name
 */
Item::Item(Sudoku *sudoku, const wxString &filename) : mSudoku(sudoku)
{
    mItemImage = make_unique<wxImage> (filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Set image for an item
 * @param filename image file name
 */
void Item::SetImage(const wxString &filename)
{
    mItemImage = make_unique<wxImage> (filename, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}

/**
 * Test to see if we hit this object with spartu.
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
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid + 1 || testY >= hit + 1)
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
 * Test to see if we hit this object with spartu.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Item::ContainerHitTest(int x, int y)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();


    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = (y - GetY() - mSudoku->GetSparty()->GetHeight()) /2  + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid + 1 || testY >= hit + 1)
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
 * @param itemNode The Xml node we are loading the item from
 * @param decNode the xml node we are loading the declaration from
 * @param tileHeight for item
 */
void Item::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    //mID = node->GetAttribute(L"id", L"0");
    itemNode->GetAttribute(L"col", L"0").ToDouble(&mCol);
    itemNode->GetAttribute(L"row", L"0").ToDouble(&mRow);
    decNode->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    decNode->GetAttribute(L"height", L"0").ToDouble(&mHeight);
    mX = (mCol) * tileHeight;
    mY = ((mRow+1) * tileHeight)- mHeight;
}

/**
 * Draw an item
 * @param graphics Device context to draw on
 * @param width of image
 * @param height of image
 */
void Item::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    if (mIsInXray)
    {
        graphics->DrawBitmap(*mItemBitmap,
                             mX,
                             mY, mWidth / 1.5, mHeight / 1.5);
    } else {
        graphics->DrawBitmap(*mItemBitmap,
                             mX,
                             mY, mWidth, mHeight);
    }

}


