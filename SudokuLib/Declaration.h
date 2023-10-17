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
    int mWidth;
    int mHeight;
    wxString mImage;
    int mValue;

public:
    Declaration();

    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_DECLARATION_H
