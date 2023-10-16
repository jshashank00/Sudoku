/**
 * @file LevelLoad.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "LevelLoad.h"

using namespace std;

/**  Load the level from a level XML file.
*
* Opens the XML file and reads the nodes, creating items as appropriate.
*
* @param filename The filename of the file to load the city from.
*/
void LevelLoad::Load(const wxString &filename)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Sudoku file");
        return;
    }

    // Once we know it is open, clear the existing data
    mSudoku.Clear();

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
        if (node->GetName() == L"game")
        {
            XmlGame(node);
        }
    }

}

/**
 * Handle a node of type game.
 * @param node XML node
 */
void LevelLoad::XmlGame(wxXmlNode *node)
{
    auto col = node->GetAttribute(L"col");
    auto row = node->GetAttribute(L"row");
    auto solution = node->GetNodeContent();
}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void LevelLoad::XmlItem(wxXmlNode *node)
{
    // A pointer for the item we are loading
    shared_ptr<Item> item;

    for( ; node; node=node->GetNext())
    {
        if(node->GetName() == L"given")
        {
            auto itemID = node->GetAttribute(L"id");
        }
        else if(node->GetName() == L"digit")
        {
            auto row = node->GetAttribute(L"row");
        }
        else if (node->GetName() == L"sparty")
        {

        }
        else if (node->GetName() == L"background")
        {

        }
        else if (node->GetName() == L"xray")
        {

        }
        else if (node->GetName() == L"container")
        {

        }
    }
    if (item != nullptr)
    {
        mSudoku.Add(item);
        item->XmlLoad(node);
    }
}

/**
 * Handle a node of type declaration.
 * @param node XML node
 */
void LevelLoad::XmlDeclaration(wxXmlNode *node)
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
        mSudoku.Add(item);
        item->XmlLoad(node);
    }
}

void LevelLoad::XmlContainer(wxXmlNode *node)
{

}