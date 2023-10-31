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

    /// To track if headbutt is activated
    bool mIsHeadButting = false;

    /// Headbutt animation time
    double mHeadbuttElapsedTime = 0.0;

    /// track if sparty is eating
    bool mIsMouthMoving = false;

    /// track if sparty is moving
    bool mIsMoving = false;

    /// track if sparty is regurgitating
    bool mIsRegurgitating = true;

    /// eating animation time
    double mMouthElapsedTime = 0.0;

    double mFront = 0.0;  ///<
    double mHeadPivotAngle = 0.0; ///< for headbutting
    double mHeadPivotX = 0.0; ///< for headbutting
    double mHeadPivotY = 0.0; ///< for headbutting
    wxString mImage1; ///< Sparty image 1
    wxString mImage2; ///< Sparty image 2
    double mMouthPivotAngle = 0.0; ///< for eating
    double mMouthPivotX = 0.0;  ///< for eating
    double mMouthPivotY = 0.0;  ///< for eating
    double mTargetX = 0.0;
    double mTargetY = 0.0;
public:
    Sparty(Sudoku *sudoku);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height) override;

    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight) override;
    void HeadButt() override;
    void Update(double deltaTime) override;
    void MouthMove(bool moving) override;
    bool HitTest(int x, int y) override;
    void SetTargetLocation(int x, int y) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitSparty(this); }
};

#endif //PROJECT1_SUDOKULIB_SPARTY_H
