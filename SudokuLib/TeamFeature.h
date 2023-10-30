/**
 * @file TeamFeature.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_TEAMFEATURE_H
#define PROJECT1_SUDOKULIB_TEAMFEATURE_H
/**
 * Class for TeamFeature
 */
#include "Item.h"
class Sudoku;
class TeamFeature : public Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// Dr.Owen image
    std::unique_ptr<wxImage> mOwenImage;

    /// The bitmap to display for Dr.Owen
    std::unique_ptr<wxBitmap> mOwenBitmap;


public:

};

#endif //PROJECT1_SUDOKULIB_TEAMFEATURE_H
