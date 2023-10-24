/**
 * @file Background.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Background.h"
#include <wx/graphics.h>
using namespace std;

//const wstring imageName = L"images/background.png";

Background::Background(Sudoku* sudoku) : Item(sudoku) {
//    mPixelWidth = width;
//    mPixelHeight = height;
//    mItemImage = make_unique<wxImage>(imageName, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}


//void Background::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    graphics->DrawBitmap(*mItemImage, 0, 0 ,mPixelWidth, mPixelHeight);
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
void Background::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
//    mItemImage = make_unique<wxImage> (image, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}