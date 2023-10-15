/**
 * @file Number.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Number.h"
#include "Sudoku.h"

using namespace std;

/**
 * Constructor
 * @param number
 * @param filename
 */
Number::Number(Sudoku *Sudoku, const wstring &filename) : Item(Sudoku, filename), mSudoku(Sudoku)
{
    mNumberImage = make_unique<wxImage> (filename, wxBITMAP_TYPE_ANY);
    mNumberBitmap = make_unique<wxBitmap>(*mNumberImage);
}

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Number::HitTest(int x, int y)
{
    double wid = mNumberBitmap->GetWidth();
    double hit = mNumberBitmap->GetHeight();

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
    return !mNumberImage->IsTransparent((int)testX, (int)testY);
}

/**
 * Load the attributes for a number node.
 *
 * This is the  base class version that loads the attributes
 * common to all number. Override this to load custom attributes
 * for specific number.
 *
 */
void Number::XmlLoad(wxXmlNode *node)
{

}

/**
 * Draw a number
 * @param dc Device context to draw on
 */
void Number::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
//    double wid = mNumberBitmap->GetWidth();
//    double hit = mNumberBitmap->GetHeight();
//    graphics->DrawBitmap(*mNumberBitmap,
//                         int(GetX() - wid / 2),
//                         int(GetY() - hit / 2), width, height);
}