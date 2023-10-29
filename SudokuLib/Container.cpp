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
    wxString frontImage = decNode->GetAttribute(L"front",L"0");
    mFrontImage = "images/" + frontImage;
    Item::SetImage(image);
    wxString image1 = decNode->GetAttribute(L"front",L"0");
    image1 = "images/" + image1;
    mFrontImage = make_unique<wxImage> (image1, wxBITMAP_TYPE_ANY);
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
                         this->GetY(), 200, 200);
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

/**
 * Draw an container
 * @param dc Device context to draw on
 */
void Container::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    Item::Draw(graphics, 48, 48);
    std::unique_ptr<wxImage> frontImage = make_unique<wxImage> (mFrontImage, wxBITMAP_TYPE_ANY);
    std::unique_ptr<wxBitmap> frontBitmap = make_unique<wxBitmap>(*frontImage);
    graphics->DrawBitmap(*frontBitmap,
                         this->GetX(),
                         this->GetY(), this->GetItemWid(), this->GetItemHit());
}