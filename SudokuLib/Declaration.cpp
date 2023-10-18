/**
 * @file Declaration.cpp
 * @author shash
 */
#include "pch.h"
#include "Declaration.h"
using namespace std;

/**
 * Constructor
 */
Declaration::Declaration()
{

}

/**
 * Load info from the xml file
 * @param node node for this item
 */
void Declaration::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}