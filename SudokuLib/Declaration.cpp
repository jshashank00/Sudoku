/**
 * @file Declaration.cpp
 * @author shash
 */

#include "Declaration.h"
using namespace std;

Declaration::Declaration()
{

}

void Declaration::XmlLoad(wxXmlNode *node)
{
    node->GetAttribute(L"width", L"0").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"0").ToDouble(&mHeight);
}