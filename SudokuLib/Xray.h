/**
 * @file Xray.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_XRAY_H
#define PROJECT1_SUDOKULIB_XRAY_H

#include "Item.h"

class Xray : public Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;
public:


};

#endif //PROJECT1_SUDOKULIB_XRAY_H
