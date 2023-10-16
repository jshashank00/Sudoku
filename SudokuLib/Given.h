/**
 * @file Given.h
 * @author Tess Murphy
 *
 * Class to represent a given number
 */

#ifndef PROJECT1_SUDOKULIB_GIVEN_H
#define PROJECT1_SUDOKULIB_GIVEN_H

#include "Item.h"

/**
 * Class to represent a Given number
 */
class Given : public Item
{
private:
    /// The number image
    std::unique_ptr<wxImage> mGivenImage;

    /// The bitmap to display for the number
    std::unique_ptr<wxBitmap> mGivenBitmap;

public:
    Given(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext>, int width, int height);


};

#endif //PROJECT1_SUDOKULIB_GIVEN_H
