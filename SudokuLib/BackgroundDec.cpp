/**
 * @file BackgroundDec.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "BackgroundDec.h"

/**
 * Load the attributes for a declaration node.
 *
 * This is the  base class version that loads the attributes
 * common to background declarations.
 *
 * @param node The Xml node we are loading the dec from
 */
void BackgroundDec::XmlLoad(wxXmlNode *node)
{
    Declaration::XmlLoad(node);
    mImage = node->GetAttribute(L"image",L"0");
}