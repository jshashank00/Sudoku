/**
 * @file Digit.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Digit.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Digit Constructor
 * @param sudoku Game we are in
 * @param filename image filename
 */
Digit::Digit(Sudoku *sudoku, const wxString &filename) : Item(sudoku, filename)
{
}

/**
 * Load the attributes for a digit node.

 * @param node The Xml node we are loading the item from
 * @param decNode the xml node we are loading the declaration from
 * @param height for item
 */
void Digit::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, tileHeight);
    decNode->GetAttribute(L"value", L"0").ToInt(&mValue);
}