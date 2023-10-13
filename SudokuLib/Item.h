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

public:
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


    void Draw(wxDC *dc);

    /**
    * Set the item location
    * @param x X location in pixels
    * @param y Y location in pixels
    */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    bool HitTest(int x, int y);
    void XmlLoad(wxXmlNode *node);

    /// The game the item is in
    Item(Sudoku *sudoku, const std::wstring &filename);
};

#endif //PROJECT1_SUDOKULIB_ITEM_H
