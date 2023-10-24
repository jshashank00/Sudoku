/**
 * @file Digit.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Digit.h"
#include <wx/graphics.h>

using namespace std;

Digit::Digit(Sudoku *sudoku) : Item(sudoku)
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
void Digit::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
    decNode->GetAttribute(L"value", L"0").ToInt(&mValue);

}