/**
 * @file Sudoku.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Sudoku.h"
#include "Sparty.h"
#include "Scoreboard.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Sudoku Constructor
 */
Sudoku::Sudoku()
{
    mBackground = make_unique<wxBitmap>(L"images/background.png", wxBITMAP_TYPE_ANY);

    // Create a sparty
    // This creates a shared pointer to sparty
    shared_ptr<Item> sparty = make_shared<Sparty>(this);
    shared_ptr<Item> scoreboard = make_shared<Scoreboard>(this);

    // Set the location
    sparty->SetLocation(100, 100);

    // Add to the list
    mItems.push_back(sparty);
    mItems.push_back(scoreboard);
}

/**
 * Getter for mItems
 * @return mItems
 */
const std::vector<std::shared_ptr<Item>>& Sudoku::GetItems() const
{
    return mItems;
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
void Sudoku::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Determine the size of the playing area in virtual pixels (up to you)
    int pixelWidth = 988;
    int pixelHeight = 750;

    // Calculate the scaling factors
    double scaleX = double(width) / double(pixelWidth);
    double scaleY = double(height) / double(pixelHeight);
    mScale = std::min(scaleX, scaleY);

    // Calculate the offsets for centering the content
    mXOffset = (width - pixelWidth * mScale) / 2.0;
    mYOffset = (height - pixelHeight * mScale) / 2.0;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    // Draw the background image
    if (mBackground) {
        graphics->DrawBitmap(*mBackground, 0, 0, pixelWidth, pixelHeight);
    }

    /*
    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    for(auto item : mItems)
    {
        item->Draw(dc);
    }
     */
    graphics->PopState();
}


/**
* Add an item to the game
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
    auto width = root->GetAttribute(L"width");
    auto height = root->GetAttribute(L"height");
    auto tileWidth = root->GetAttribute(L"tilewidth");
    auto tileHeight = root->GetAttribute(L"tileheight");
    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto node = root->GetChildren();
    for( ; node; node=node->GetNext())
    {
        if (node->GetName() == L"declarations")
        {
            XmlDeclaration(node);
        }
        if (node->GetName() == L"items")
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
 * Handle a node of type declaration.
 * @param node XML node
 */
void Sudoku::XmlDeclaration(wxXmlNode *node)
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

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Sudoku::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}