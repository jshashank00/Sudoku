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
#include "Container.h"


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
    root->GetAttribute(L"width").ToDouble(&mWidth);
    root->GetAttribute(L"height").ToDouble(&mHeight);
    root->GetAttribute(L"tilewidth").ToDouble(&mTileWidth);
    root->GetAttribute(L"tileheight").ToDouble(&mTileHeight);
    mPixelWidth = mWidth * mTileWidth;
    mPixelHeight = mHeight * mTileHeight;
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
    wxXmlNode* decNode;
    bool backgroundThere = false;
    auto itemNode = node->GetChildren();
    for( ; itemNode; itemNode=itemNode->GetNext())
    {
        wxString id = itemNode->GetAttribute(L"id");
        decNode = mMap.find(id)->second;

        wxString image = "images/" + decNode->GetAttribute(L"image",L"0");

        if (itemNode->GetName() == L"given")
        {
            item = make_shared<Given>(mSudoku, image);
            mSudoku->Add(item);
            item->XmlLoad(itemNode, decNode, mTileHeight);
        }
        else if (itemNode->GetName() == L"digit")
        {
            item = make_shared<Digit>(mSudoku, image);
            mSudoku->Add(item);
            item->XmlLoad(itemNode, decNode, mTileHeight);

        }
        else if (itemNode->GetName() == L"sparty")
        {
            item = make_shared<Sparty>(mSudoku);
            mSudoku->Add(item);
            mSudoku->SetSparty(item);
            item->XmlLoad(itemNode, decNode, mTileHeight);
        }
        else if (itemNode->GetName() == L"background")
        {
            if (!backgroundThere)
            {
//                int * height;
//                int * width;
//                decNode->GetAttribute(L"height", L"0").ToInt(height);
//                decNode->GetAttribute(L"width", L"0").ToInt(width);
//                mSudoku->SetPixelHeight(*height);
//                mSudoku->SetPixelWidth(*width);
//                backgroundThere = true;
            }
            item = make_shared<Background>(mSudoku, image, mPixelWidth, mPixelHeight );
            mSudoku->Add(item);
            item->XmlLoad(itemNode, decNode, mTileHeight);
            //mBackgroundImage = decNode->GetAttribute(L"image");
            //decNode->GetAttribute(L"width", L"0").ToDouble(&mWidthBackground);
            //decNode->GetAttribute(L"height", L"0").ToDouble(&mHeightBackground);
        }
        else if (itemNode->GetName() == L"xray")
        {
            item = make_shared<Xray>(mSudoku);
            mSudoku->Add(item);
            item->XmlLoad(itemNode, decNode, mTileHeight);
        }
        else if (itemNode->GetName() == L"container")
        {
            XmlContainerItem(itemNode);
        }
    }
    if (item != nullptr)
    {
//        mSudoku->Add(item);
//        item->XmlLoad(itemNode, decNode);
    }
}

/**
 * Handle a node of type declaration.
 * @param node XML node
 */
void LevelLoad::XmlDeclaration(wxXmlNode *node)
{
    // A pointer for the item we are loading
    wxString id;
    auto childNode = node->GetChildren();
    for( ; childNode; childNode=childNode->GetNext())
    {
        id = childNode->GetAttribute(L"id");
        mMap.insert({id, childNode});
    }
}

/**
 * Handle a node of type container.
 * @param node XML node
 */
void LevelLoad::XmlContainerItem(wxXmlNode *node)
{
    // A pointer for the item we are loading
    shared_ptr<Item> item;
    shared_ptr<Container> container;
    container = make_shared<Container>(mSudoku);
    mSudoku->Add(container);

    wxXmlNode* decNode;
    wxString id = node->GetAttribute(L"id");
    decNode = mMap.find(id)->second;
    container->XmlLoad(node, decNode, mTileHeight);

//    node->GetAttribute(L"image");
    auto childNode = node->GetChildren();
    for( ; childNode; childNode=childNode->GetNext())
    {
        wxString image = "images/" + decNode->GetAttribute(L"image",L"0");
        wxString digitID = childNode->GetAttribute(L"id");
        decNode = mMap.find(digitID)->second;
        item = make_shared<Digit>(mSudoku, image);
        mSudoku->Add(item);
        item->XmlLoad(childNode, decNode, mTileHeight);
    }
}


