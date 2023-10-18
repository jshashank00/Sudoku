/**
 * @file BackgroundDec.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_BACKGROUNDDEC_H
#define PROJECT1_SUDOKULIB_BACKGROUNDDEC_H

#include "Declaration.h"
class BackgroundDec : public Declaration
{
private:
    wxString mImage;
public:
    BackgroundDec(){};
    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_BACKGROUNDDEC_H
