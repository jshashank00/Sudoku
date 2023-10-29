/**
 * @file Container.cpp
 * @author jbrown
 */

#include "pch.h"
#include "Container.h"
#include <wx/graphics.h>
using namespace std;

Container::Container(Sudoku *sudoku) : Item(sudoku)
{
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
void Container::XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, height);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
    wxString front_image = decNode->GetAttribute(L"front",L"0");
    front_image = "images/" + front_image;
    mFrontImage = make_unique<wxImage> (front_image, wxBITMAP_TYPE_ANY);
    mFrontBitmap = make_unique<wxBitmap>(*mFrontImage);
}

void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    Item::Draw(graphics, width, height);
    for (auto item : mContainedItems)
    {
        item->Draw(graphics, width, height);
    }
    double wid = mFrontBitmap->GetWidth();
    double hit = mFrontBitmap->GetHeight();
    graphics->DrawBitmap(*mFrontBitmap,
                         this->GetX(),
                         this->GetY(), wid, hit);
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
//void Container::XmlLoadFront(wxXmlNode *itemNode, wxXmlNode *decNode, double height)//, shared_ptr<Declaration> decNode)
//{
//    Item::XmlLoad(itemNode, decNode, height);
//    wxString image = decNode->GetAttribute(L"front",L"0");
//    image = "images/" + image;
//    Item::SetImage(image);
//}

void Container::AddItem(std::shared_ptr<Item> item) {
    mContainedItems.push_back(item);
    item->SetInContainer(true); // Mark the item as being in a container
}

std::vector<std::shared_ptr<Item>> Container::GetContainedItems() const {
    return mContainedItems;
}

void Container::Clear()
{
    mContainedItems.clear();
}