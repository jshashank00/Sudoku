/**
 * @file NumberDec.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_NUMBERDEC_H
#define PROJECT1_SUDOKULIB_NUMBERDEC_H
#include "Declaration.h"
class NumberDec : public Declaration
{
private:
    wxString mImage;
    int mValue;
public:

    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_NUMBERDEC_H
