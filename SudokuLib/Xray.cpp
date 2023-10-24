/**
 * @file Xray.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "Xray.h"
#include <wx/graphics.h>
using namespace std;

//const wstring XrayImageName = L"images/xray.png";

Xray::Xray(Sudoku* sudoku) : Item(sudoku)
{
//    mItemImage = make_unique<wxImage>(XrayImageName, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}


//void Xray::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    double wid = mItemBitmap->GetWidth();
//    double hit = mItemBitmap->GetHeight();
//    double x = 30; // Left
//    double y = height - hit; // Bottom
//
//    // Draw the image at the calculated position
//    graphics->DrawBitmap(*mItemBitmap, x, y, wid, hit);
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
void Xray::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
//    mItemImage = make_unique<wxImage> (image, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    decNode->GetAttribute(L"capacity", L"0").ToInt(&mCapacity);

}