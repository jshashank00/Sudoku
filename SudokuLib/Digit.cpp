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

//void Digit::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    //Item::Draw(graphics, width, height);
//    double wid = mNumberBitmap->GetWidth();
//    double hit = mNumberBitmap->GetHeight();
//    graphics->DrawBitmap(*mNumberBitmap,
//                         int(GetX() - wid / 2),
//                         int(GetY() - hit / 2), 50, 50);
//}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void Digit::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
    mNumberImage = make_unique<wxImage> (image, wxBITMAP_TYPE_ANY);
    mNumberBitmap = make_unique<wxBitmap>(*mNumberImage);
    decNode->GetAttribute(L"value", L"0").ToInt(&mValue);

}