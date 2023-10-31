/**
 * @file TeamFeature.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "TeamFeature.h"
#include <wx/graphics.h>
using namespace std;

TeamFeature::TeamFeature(Sudoku *sudoku) : Item(sudoku)
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
void TeamFeature::XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode, height);
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
    wxString front_image = decNode->GetAttribute(L"front",L"0");
    front_image = "images/" + front_image;
    mOwenImage = make_unique<wxImage> (front_image, wxBITMAP_TYPE_ANY);
    mOwenBitmap = make_unique<wxBitmap>(*mOwenImage);
}