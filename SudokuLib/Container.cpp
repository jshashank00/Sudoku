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

const std::vector<std::shared_ptr<Item>>& Container::GetContainedItems() const {
    return mContainedItems;
}