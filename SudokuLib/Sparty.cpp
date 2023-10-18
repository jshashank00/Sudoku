/**
 * @file Sparty.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Sparty.h"
#include <wx/graphics.h>

using namespace std;

/// Character speed in pixels per second
const double MaxSpeed = 400.00;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;

/// Sparty filename
//const wstring SpartyImageName = L"images/sparty-1.png";

/// Sparty filename
//const wstring SpartyImageMouthName = L"images/sparty-2.png";

/**
 * Constructor
 * @param sudoku The sudoku game we are in
 * @param filename Filename for the image we use
 */
Sparty::Sparty(Sudoku *sudoku) :
    Item(sudoku)
{
//    mItemImage = make_unique<wxImage> (SpartyImageMouthName, wxBITMAP_TYPE_ANY);
//    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
//    sudoku->SetSparty(this);
}

void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    Item::Draw(graphics, 100, 100);
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    graphics->DrawBitmap(*mItemBitmap,
                   int(GetX() - wid / 2),
                   int(GetY() - hit / 2), wid, hit);
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
void Sparty::XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode)//, shared_ptr<Declaration> decNode)
{
    Item::XmlLoad(itemNode, decNode);
    mImage1 = decNode->GetAttribute(L"image1",L"0");
    mImage2 = decNode->GetAttribute(L"image2",L"0");
    mImage1 = "images/" + mImage1;
    mImage2 = "images/" + mImage2;
    Item::SetImage(mImage1);
    mItemImage = make_unique<wxImage> (mImage2, wxBITMAP_TYPE_ANY);
    mItemBitmap = make_unique<wxBitmap>(*mItemImage);
    decNode->GetAttribute(L"front", L"0").ToDouble(&mFront);
    decNode->GetAttribute(L"head-pivot-angle").ToDouble(&mHeadPivotAngle);
    decNode->GetAttribute(L"head-pivot-x").ToDouble(&mHeadPivotX);
    decNode->GetAttribute(L"head-pivot-y").ToDouble(&mHeadPivotY);
    decNode->GetAttribute(L"mouth-pivot-x").ToDouble(&mMouthPivotX);
    decNode->GetAttribute(L"mouth-pivot-y").ToDouble(&mHeadPivotY);
    decNode->GetAttribute(L"target-x").ToDouble(&mTargetX);
    decNode->GetAttribute(L"target-y").ToDouble(&mTargetY);
}