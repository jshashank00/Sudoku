/**
 * @file Xray.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "Xray.h"
#include <wx/graphics.h>
using namespace std;

/**
 * Xray Constructor
 * @param sudoku Game we are in
 */
Xray::Xray(Sudoku* sudoku) : Item(sudoku)
{
}

/**
 * Load the attributes for an xray node.
 *
 * @param itemNode The Xml node we are loading the item from
 * @param decNode the xml node we are loading the declaration from
 * @param tileHeight for tile
 */
void Xray::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
    decNode->GetAttribute(L"capacity", L"0").ToInt(&mCapacity);

}

/**
 * Add an item to the xray list
 * @param item Item to be added to the list
 * @return true if added, false otherwise
 */
bool Xray::AddItem(std::shared_ptr<Item> item) {
    // only add if there is room
    if (mCapacity > mTotalNumbers)
    {
        mXrayItems.push_back(item);
        item->SetInXray(true); // Mark the item as being in a container
        mTotalNumbers += 1; // update total numbers
        showMessage = false;
        return true;
    } else {
        // Access the MessageBoard and set the showMessage flag

//        mMessageBoard->GetMessage();
        showMessage = true;
        // call message to say "I'm full" here
        auto game = GetSudoku();
        GetSudoku()->SetGameOver(true);
        return false;
    }
}

/**
 * @return xray items list
 */
std::vector<std::shared_ptr<Item>> Xray::GetXrayItems() {
    return mXrayItems;
}

/**
 * Remove item from xray list
 * @param item Item to be added to the list
 */
void Xray::RemoveDigit(std::shared_ptr<Item> item)
{
    auto loc = find(begin(mXrayItems), end(mXrayItems), item);
    if (loc != end(mXrayItems))
    {
        mXrayItems.erase(loc);
        mTotalNumbers -= 1;
    }
}