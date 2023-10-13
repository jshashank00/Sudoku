/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"
using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);
}


/**  Test an x,y click location to see if it clicked
* on some item in the game.
* @param x X location
* @param y Y location
* @return Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Sudoku::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }
    return  nullptr;
}

/**
 * Draw the game
 * @param dc The device context to draw on
 */
void Sudoku::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    for(auto item : mItems)
    {
        item->Draw(dc);
    }
//    dc->SetFont(font);
//    dc->SetTextForeground(wxColour(0, 64, 0));
//    dc->DrawText(L"Under the Sea!", 10, 10);
}

/**
* Add an item to the aquarium
 * @param item New item to add
*/
void Sudoku::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(100, 200);
    mItems.push_back(item);
}

/**  Load the city from a level XML file.
*
* Opens the XML file and reads the nodes, creating items as appropriate.
*
* @param filename The filename of the file to load the city from.
*/
void Sudoku::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Sudoku file");
        return;
    }

    // Once we know it is open, clear the existing data
    Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto node = root->GetChildren();
    for( ; node; node=node->GetNext())
    {
        if (node->GetName() == L"description")
        {
            XmlItem(node);
        }
    }

}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Sudoku::XmlItem(wxXmlNode *node)
{
    // A pointer for the item we are loading
    shared_ptr<Item> item;

    // We have an item. What type?
    auto givenID = node->GetAttribute(L"given id");
    auto width = node->GetAttribute(L"width");
    auto height = node->GetAttribute(L"height");
    auto image = node->GetAttribute(L"value");
    if (item != nullptr)
    {
        Add(item);
        item->XmlLoad(node);
    }
}

/**
*  Clear the city data.
*
* Deletes all known items in the city.
*/
void Sudoku::Clear()
{
    mItems.clear();
}