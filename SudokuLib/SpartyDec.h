/**
 * @file SpartyDec.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SPARTYDEC_H
#define PROJECT1_SUDOKULIB_SPARTYDEC_H
#include "Declaration.h"
class SpartyDec : public Declaration
{
private:
    double mFront;  ///<
    double mHeadPivotAngle; ///< for headbutting
    double mHeadPivotX; ///< for headbutting
    double mHeadPivotY; ///< for headbutting
    wxString mImage1; ///< Sparty image 1
    wxString mImage2; ///< Sparty image 2
    double mMouthPivotAngle; ///< for eating
    double mMouthPivotX;  ///< for eating
    double mMouthPivotY;  ///< for eating
    double mTargetX;
    double mTargetY;

public:
    SpartyDec(){};

    void XmlLoad(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_SPARTYDEC_H
