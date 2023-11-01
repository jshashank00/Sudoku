/**
 * @file Container.cpp
 * @author jbrown
 */

#include "pch.h"
#include "Container.h"
#include <wx/graphics.h>
using namespace std;

/**
 * Container Constructor
 * @param sudoku Game we are in
 */
Container::Container(Sudoku *sudoku) : Item(sudoku)
{
}

/**
 * Load the attributes for a container node.
 *
 * @param itemNode The Xml node we are loading the item from
 * @param decNode the xml node we are loading the declaration from
 * @param height for item
 */
void Container::XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height)
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

/**
 * Draw an item
 * @param graphics Device context to draw on
 * @param height of image
 * @param width of image
 */
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
 * Add an item to the container list
 * @param item Item to be added to the list
 */
void Container::AddItem(std::shared_ptr<Item> item) {
    mContainedItems.push_back(item);
    item->SetInContainer(true); // Mark the item as being in a container
}

/**
 * Getter for contained items
 * @return contained items list
 */
std::vector<std::shared_ptr<Item>> Container::GetContainedItems() const {
    return mContainedItems;
}

/**
 * Clear container list
 */
void Container::Clear()
{
    mContainedItems.clear();
}