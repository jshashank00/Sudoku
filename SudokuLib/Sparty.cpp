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

/**
 * Function for handling Headbutt motion
 */
void Sparty::HeadButt()
{
    mIsHeadButting = !mIsHeadButting;
    mHeadbuttElapsedTime = 0.0;
}

/**
 * Function for handling Eating motion
 */
void Sparty::MouthMove()
{
    mIsMouthMoving = !mIsMouthMoving;
}

/**
 * Draw items on screen
 * @param graphics
 * @param width width of the item
 * @param height height of the item
 */
void Sparty::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    double Hwid = mHeadBitmap->GetWidth();
    double Hhit = mHeadBitmap->GetHeight();

    if (mIsMouthMoving)
    {
        double absMouthPivotX = GetX() - wid / 2 + mMouthPivotX;
       double absMouthPivotY = GetY() - hit / 2 + mMouthPivotY;
        graphics->PushState();

        double progress = mMouthElapsedTime / EatingTime;

        if(progress < 0.5)
        {
            progress = progress * 2;
        }
        else
        {
            progress = 2 - progress * 2;
        }
        double angle = mMouthPivotAngle * progress;
        graphics->DrawBitmap(*mHeadBitmap,
                             int(GetX() - Hwid / 2),
                             int(GetY() - Hhit / 2), wid, hit);
        graphics->Translate(absMouthPivotX, absMouthPivotY);
        graphics->Rotate(angle);
        graphics->Translate(-absMouthPivotX, -absMouthPivotY);
        graphics->DrawBitmap(*mItemBitmap,
                             int(GetX() - wid / 2),
                             int(GetY() - hit / 2), wid, hit);
        graphics->PopState();
    }

    else if (mIsHeadButting)
    {
        double absPivotX = GetX() - wid / 2 + mHeadPivotX;
        double absPivotY = GetY() - hit / 2 + mHeadPivotY;
        graphics->PushState();
        double progress = mHeadbuttElapsedTime / HeadbuttTime;

        if(progress < 0.5)
        {
            progress = progress * 2;
        }
        else
        {
            progress = 2 - progress * 2;
        }
        double angle = mHeadPivotAngle * progress;
        graphics->Translate(absPivotX, absPivotY);
        graphics->Rotate(angle);  // Assuming this is in radians
        graphics->Translate(-absPivotX, -absPivotY);

        graphics->DrawBitmap(*mItemBitmap,
                             int(GetX() - wid / 2),
                             int(GetY() - hit / 2), wid, hit);
        graphics->DrawBitmap(*mHeadBitmap,
                             int(GetX() - Hwid / 2),
                             int(GetY() - Hhit / 2), wid, hit);
        graphics->PopState();
    }
    else
    {
        graphics->DrawBitmap(*mItemBitmap,
                             int(GetX() - wid / 2),
                             int(GetY() - hit / 2), wid, hit);
        graphics->DrawBitmap(*mHeadBitmap,
                             int(GetX() - Hwid / 2),
                             int(GetY() - Hhit / 2), wid, hit);
    }
}

/**
 * Update sparty animations
 * @param elapsed time for animations
 */
void Sparty::Update(double elapsed)
{
    if (mIsHeadButting)
    {
        mHeadbuttElapsedTime += elapsed;
        if (mHeadbuttElapsedTime > HeadbuttTime)
        {
            mIsHeadButting = false;
            mHeadbuttElapsedTime = 0.0;
        }
    }

    if (mIsMouthMoving)
    {
        mMouthElapsedTime += elapsed;
        if (mMouthElapsedTime > HeadbuttTime)
        {
            mIsMouthMoving = false;
            mMouthElapsedTime = 0.0;
        }
    }
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
    mHeadImage = make_unique<wxImage> (mImage1, wxBITMAP_TYPE_ANY);
    mHeadBitmap = make_unique<wxBitmap>(*mHeadImage);
    decNode->GetAttribute(L"front", L"0").ToDouble(&mFront);
    decNode->GetAttribute(L"head-pivot-angle").ToDouble(&mHeadPivotAngle);
    decNode->GetAttribute(L"head-pivot-x").ToDouble(&mHeadPivotX);
    decNode->GetAttribute(L"head-pivot-y").ToDouble(&mHeadPivotY);
    decNode->GetAttribute(L"mouth-pivot-angle").ToDouble(&mMouthPivotAngle);
    decNode->GetAttribute(L"mouth-pivot-x").ToDouble(&mMouthPivotX);
    decNode->GetAttribute(L"mouth-pivot-y").ToDouble(&mMouthPivotY);
    decNode->GetAttribute(L"target-x").ToDouble(&mTargetX);
    decNode->GetAttribute(L"target-y").ToDouble(&mTargetY);
}