/**
 * @file Background.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Background.h"
#include <wx/graphics.h>
using namespace std;

Background::Background(Sudoku* sudoku, const wxString &filename, double width, double height) : Item(sudoku, filename) {

}

//void Background::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    graphics->DrawBitmap(*mItemImage, 0, 0 ,mPixelWidth, mPixelHeight);
//}
