/**
 * @file Digit.h
 * @author Tess Murphy
 *
 * Class to represent a digit item
 */

#ifndef PROJECT1_SUDOKULIB_DIGIT_H
#define PROJECT1_SUDOKULIB_DIGIT_H

#include "Item.h"
#include "Number.h"

/**
 * Class to represent a Digit Item
 */
class Digit : public Number
{
private:
    /// The item image
    std::unique_ptr<wxImage> mNumberImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mNumberBitmap;

public:
    Digit(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext>, int width, int height);

};

#endif //PROJECT1_SUDOKULIB_DIGIT_H
