/**
 * @file Given.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Given.h"
#include <wx/graphics.h>

using namespace std;


/**
 * Given Constructor
 * @param sudoku Game we are in
 * @param filename image filename
 */
Given::Given(Sudoku *sudoku, const wxString &filename) : Item(sudoku, filename)
{
}

/**
 * Load the attributes for a given node.
 * @param node The Xml node we are loading the item from
 * @param decNode the xml node we are loading the declaration from
 * @param height for item
 */
void Given::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    decNode->GetAttribute(L"value", L"0").ToInt(&mValue);
}