/**
 * @file Container.cpp
 * @author jbrown
 */

#include "pch.h"
#include "Container.h"
using namespace std;

Container::Container(Sudoku *sudoku) : Item(sudoku)
{
}

//void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    //Item::Draw(graphics, width, height);
//    double wid = mItemBitmap->GetWidth();
//    double hit = mItemBitmap->GetHeight();
//    graphics->DrawBitmap(*mItemBitmap,
//                         int(GetX() - wid / 2),
//                         int(GetY() - hit / 2), 48, 48);
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
void Container::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode);
    wxString image = decNode->GetAttribute(L"image",L"0");
    mFront = decNode->GetAttribute(L"front", L"0");
    image = "images/" + image;
    Item::SetImage(image);
    mItemImage = make_unique<wxImage> (image, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
}