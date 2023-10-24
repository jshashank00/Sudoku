/**
 * @file Given.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Given.h"
#include <wx/graphics.h>

using namespace std;

const std::wstring GivenImageName = L"images/0b.png";

//Given::Given(Sudoku *sudoku) :
//    Item(sudoku, GivenImageName)
//{
    //mGivenImage = make_unique<wxImage> (GivenImageName, wxBITMAP_TYPE_ANY);
    //mGivenBitmap = make_unique<wxBitmap>(*mGivenImage);
//}

Given::Given(Sudoku *sudoku) : Item(sudoku)
{

}

//void Given::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
//{
//    //Item::Draw(graphics, width, height);
//    double wid = mGivenBitmap->GetWidth();
//    double hit = mGivenBitmap->GetHeight();
//    graphics->DrawBitmap(*mGivenBitmap,
//                         int(GetX() - wid / 2),
//                         int(GetY() - hit / 2), 48, 48);
//}

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
    wxString image = decNode->GetAttribute(L"image",L"0");
    image = "images/" + image;
    Item::SetImage(image);
    mGivenImage = make_unique<wxImage> (image, wxBITMAP_TYPE_ANY);
    mGivenBitmap = make_unique<wxBitmap>(*mGivenImage);
    decNode->GetAttribute(L"value", L"0").ToInt(&mValue);

}