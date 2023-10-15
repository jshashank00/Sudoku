/**
 * @file Number.h
 * @author Tess Murphy
 *
 * Base class for numbers
 */

#ifndef PROJECT1_SUDOKULIB_NUMBER_H
#define PROJECT1_SUDOKULIB_NUMBER_H

#include "Item.h"
#include <wx/xml/xml.h>
class Sudoku;

/**
 * Base class for number
 * This applies to all numbers in the game
 */
class Number : public Item {
private:
    /// The number image
    std::unique_ptr<wxImage> mNumberImage;

    /// The bitmap to display for the number
    std::unique_ptr<wxBitmap> mNumberBitmap;

    /// The game the number is in
    Sudoku *mSudoku;

    /// number location
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


    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    /**
    * Set the number location
    * @param x X location in pixels
    * @param y Y location in pixels
    */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    bool HitTest(int x, int y);
    void XmlLoad(wxXmlNode *node);

    /// The game the number is in
    Number(Sudoku *Sudoku, const std::wstring &Filename);

};

#endif //PROJECT1_SUDOKULIB_NUMBER_H
