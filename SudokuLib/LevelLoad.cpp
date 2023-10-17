/**
 * @file LevelLoad.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "LevelLoad.h"
#include "Given.h"
#include "Digit.h"
#include "Sparty.h"
#include "Xray.h"
#include "Background.h"
#include "Declaration.h"


using namespace std;

/**  Load the level from a level XML file.
*
* Opens the XML file and reads the nodes, creating items as appropriate.
*
* @param filename The filename of the file to load the city from.
*/
LevelLoad::LevelLoad(const wxString &filename, Sudoku * sudoku) :mSudoku(sudoku)
{
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Sudoku file");
        return;
    }

    // Once we know it is open, clear the existing data
    mSudoku->Clear();

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();
    mWidth = root->GetAttribute(L"width");
    mHeight = root->GetAttribute(L"height");
    mTileWidth = root->GetAttribute(L"tilewidth");
    mTileHeight = root->GetAttribute(L"tileheight");
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
    mCol = node->GetAttribute(L"col");
    mRow = node->GetAttribute(L"row");
    mSolution = node->GetNodeContent();
}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void LevelLoad::XmlItem(wxXmlNode *node)
{
    // A pointer for the item we are loading
    shared_ptr<Item> item;
    auto childNode = node->GetChildren();
    for( ; childNode; childNode=childNode->GetNext())
    {
        if(childNode->GetName() == L"given")
        {
            auto item = make_shared<Given>(mSudoku);
            item->XmlLoad(node);
        }
        else if(childNode->GetName() == L"digit")
        {
            auto item = make_shared<Digit>(mSudoku);
        }
        else if (childNode->GetName() == L"sparty")
        {
            auto item = make_shared<Sparty>(mSudoku);
        }
        else if (childNode->GetName() == L"background")
        {
//            item = make_shared<Background>(this);
        }
        else if (childNode->GetName() == L"xray")
        {
            auto item = make_shared<Xray>(mSudoku);
        }
        else if (childNode->GetName() == L"container")
        {
            XmlContainer(node);
        }
    }
    if (item != nullptr)
    {
        mSudoku->Add(item);
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
    shared_ptr<Declaration> dec;
    auto childNode = node->GetChildren();
    for( ; childNode; childNode=childNode->GetNext())
    {
        if(childNode->GetName() == L"given")
        {
//            dec = make_shared<Given>(this);
        }
        else if(childNode->GetName() == L"digit")
        {
//            dec = make_shared<Digit>(this);
        }
        else if (childNode->GetName() == L"sparty")
        {
//            item = make_shared<Sparty>(this);
        }
        else if (childNode->GetName() == L"background")
        {
            mBackground = childNode->GetAttribute(L"image");
//            item = make_shared<Background>(this);
        }
        else if (childNode->GetName() == L"xray")
        {
//             item = make_shared<Xray>(this);
        }
        else if (childNode->GetName() == L"container")
        {
            XmlContainer(node);
        }
    }
//    if (item != nullptr)
//    {
//        mSudoku.Add(item);
//        item->XmlLoad(node);
//    }
}

/**
 * Handle a node of type container.
 * @param node XML node
 */
void LevelLoad::XmlContainer(wxXmlNode *node)
{

}