/**
 * @file Cauldron.h
 * @author jbrown
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_CAULDRON_H
#define PROJECT1_SUDOKULIB_CAULDRON_H

#include "Item.h"

class Cauldron : public Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    int mWidth;  // Width of the container
    int mHeight; // Height of the container
public:
    Cauldron(Sudoku* sudoku); // Add width and height parameters
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_SUDOKULIB_CAULDRON_H
