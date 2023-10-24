/**
 * @file Given.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Given.h"
#include <wx/graphics.h>

using namespace std;


Given::Given(Sudoku *sudoku, const wxString &filename) : Item(sudoku, filename)
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
void Given::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    decNode->GetAttribute(L"value", L"0").ToInt(&mValue);
}