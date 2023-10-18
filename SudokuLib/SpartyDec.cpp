/**
 * @file SpartyDec.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "SpartyDec.h"


/**
 * Load info from the xml file
 * @param node node for this item
 */
void SpartyDec::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    node->GetAttribute(L"front", L"0").ToDouble(&mFront);
    node->GetAttribute(L"head-pivot-angle", L"0").ToDouble(&mHeadPivotAngle);
    node->GetAttribute(L"head-pivot-x", L"0").ToDouble(&mHeadPivotX);
    node->GetAttribute(L"head-pivot-y", L"0").ToDouble(&mHeadPivotY);
    node->GetAttribute(L"image1", &mImage1);
    node->GetAttribute(L"image2", &mImage2);
    node->GetAttribute(L"mouth-pivot-angle", L"0").ToDouble(&mMouthPivotAngle);
    node->GetAttribute(L"mouth-pivot-x", L"0").ToDouble(&mMouthPivotX);
    node->GetAttribute(L"mouth-pivot-y", L"0").ToDouble(&mMouthPivotY);
    node->GetAttribute(L"target-x", L"0").ToDouble(&mTargetX);
    node->GetAttribute(L"target-y", L"0").ToDouble(&mTargetY);
}