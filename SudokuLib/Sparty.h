/**
 * @file Sparty.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SPARTY_H
#define PROJECT1_SUDOKULIB_SPARTY_H

/**
 * Class for sparty
 */
#include "Item.h"
class Sudoku;
class Sparty : public Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// The item image
    std::unique_ptr<wxImage> mHeadImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mHeadBitmap;

    bool mIsHeadButting = false; // To track if headbutt is activated
    double mHeadbuttElapsedTime = 0.0;

    /// track if sparty is eating
    bool mIsMouthMoving = false;

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
    Sparty(Sudoku *sudoku);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode);
    void ToggleHeadButt();
    void Update(double deltaTime);
    void ToggleMouthMove();
};

#endif //PROJECT1_SUDOKULIB_SPARTY_H
