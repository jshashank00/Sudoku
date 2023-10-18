/**
 * @file NumberDec.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "NumberDec.h"

/**
 * Load the attributes for a declaration node.
 *
 * This is the  base class version that loads the attributes
 * common to number declarations.
 *
 * @param node The Xml node we are loading the dec from
 */
void NumberDec::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = node->GetAttribute(L"image",L"0");
    node->GetAttribute(L"value", L"0").ToInt(&mValue);
}
