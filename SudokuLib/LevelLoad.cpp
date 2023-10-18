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
#include "SpartyDec.h"
#include "BackgroundDec.h"
#include "NumberDec.h"
#include "XrayDec.h"


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
    wxXmlNode* decNode;
    auto itemNode = node->GetChildren();
    for( ; itemNode; itemNode=itemNode->GetNext())
    {
        wxString id = itemNode->GetAttribute(L"id");
        decNode = mMap.find(id)->second;
        if(itemNode->GetName() == L"given")
        {

            //wxString mImage = decNode->GetAttribute(L"image");
            //int value;
            //decNode->GetAttribute(L"value", L"0").ToInt(&value);

            item = make_shared<Given>(mSudoku);
            mSudoku->Add(item);
            item->XmlLoad(itemNode, decNode);

            //mSudoku->Add(item);
//            item->XmlLoad(node);
        }
        else if(itemNode->GetName() == L"digit")
        {
//            item = make_shared<Digit>(mSudoku);
        }
        else if (itemNode->GetName() == L"sparty")
        {
            item = make_shared<Sparty>(mSudoku);
            mSudoku->Add(item);
            mSudoku->SetSparty(item);
            item->XmlLoad(itemNode, decNode);
//            item = make_shared<Sparty>(mSudoku);
        }
        else if (itemNode->GetName() == L"background")
        {
//            item = make_shared<Background>(this);
        }
        else if (itemNode->GetName() == L"xray")
        {
            item = make_shared<Xray>(mSudoku);
//             item = make_shared<Xray>(mSudoku);
        }
        else if (itemNode->GetName() == L"container")
        {
            XmlContainer(node);
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
    shared_ptr<Declaration> dec;
    wxString id;
    auto childNode = node->GetChildren();
    for( ; childNode; childNode=childNode->GetNext())
    {
        id = childNode->GetAttribute(L"id");
        if(childNode->GetName() == L"given")
        {
              //dec = make_shared<NumberDec>();
              mMap.insert({id, childNode});
              //dec->XmlLoad(childNode);
//              mMap.insert({id, dec});
        }
        else if(childNode->GetName() == L"digit")
        {
            mMap.insert({id, childNode});
            //dec = make_shared<NumberDec>();
            //dec->XmlLoad(childNode);
//            id = childNode->GetAttribute(L"id");
//            mMap.insert({id, dec});
        }
        else if (childNode->GetName() == L"sparty")
        {
            mMap.insert({id, childNode});
            //dec = make_shared<SpartyDec>();
//            dec->XmlLoad(childNode);
//            id = childNode->GetAttribute(L"id");
//            mMap.insert({id, dec});
        }
        else if (childNode->GetName() == L"background")
        {
            mMap.insert({id, childNode});
            //dec = make_shared<BackgroundDec>();
            mBackground = childNode->GetAttribute(L"image");
//            item = make_shared<Background>();
            //dec->XmlLoad(childNode);
//            id = childNode->GetAttribute(L"id");
//            mMap.insert({id, dec});
        }
        else if (childNode->GetName() == L"xray")
        {
            mMap.insert({id, childNode});
             //dec = make_shared<XrayDec>();
               //dec->XmlLoad(childNode);
//            id = childNode->GetAttribute(L"id");
//            mMap.insert({id, dec});
        }
        else if (childNode->GetName() == L"container")
        {
            XmlContainer(node);
        }
    }
}

/**
 * Handle a node of type container.
 * @param node XML node
 */
void LevelLoad::XmlContainer(wxXmlNode *node)
{

}

