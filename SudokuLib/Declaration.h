/**
 * @file Declaration.h
 * @author shash
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_DECLARATION_H
#define PROJECT1_SUDOKULIB_DECLARATION_H
#include <wx/xml/xml.h>

class Declaration
{
private:
    double mWidth;
    double mHeight;

public:
    Declaration();
    virtual void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_DECLARATION_H
