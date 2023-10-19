/**
 * @file Item.h
 * @author Lillian Yanke
 *
 * Base class for any item in our game
 */

#ifndef PROJECT1_SUDOKULIB_ITEM_H
#define PROJECT1_SUDOKULIB_ITEM_H

#include <wx/xml/xml.h>
class Sudoku;
class Declaration;

/**
 * Base class for any item in our game
 */
class Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// The game the item is in
    Sudoku *mSudoku;

    /// Item location
    double mX = 0;
    double mY = 0;
    double mCol = 0;
    double mRow = 0;
    double mWidth; ///<Width of the image
    double mHeight; ///<Height of the image

    /// Item id
    //wxString mID;

public:
    void SetImage(const wxString &filename);

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }


    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    /**
    * Set the item location
    * @param x X location in pixels
    * @param y Y location in pixels
    */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    bool HitTest(int x, int y);
    virtual void XmlLoad(wxXmlNode *node, wxXmlNode *decNode);

    /// Constructor
    Item(Sudoku *sudoku, const std::wstring &filename);

    ///Constructor
    Item(Sudoku *sudoku);

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}

    /**
     * Handle the Mouth movement
     */
    virtual void MouthMove() {}

    /**
     * Handle the headbutt movement
     */
    virtual void HeadButt() {}
    //void XmlLoad(wxXmlNode *node, std::shared_ptr<Declaration> decNode);
};

#endif //PROJECT1_SUDOKULIB_ITEM_H
