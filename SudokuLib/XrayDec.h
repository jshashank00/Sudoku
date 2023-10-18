/**
 * @file XrayDec.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_XRAYDEC_H
#define PROJECT1_SUDOKULIB_XRAYDEC_H

#include "Declaration.h"
class XrayDec : public Declaration
{
private:
    wxString mImage;
    int mCapacity;
public:

    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_XRAYDEC_H
