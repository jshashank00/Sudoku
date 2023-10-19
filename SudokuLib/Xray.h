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

    /// capacity of numbers xray can hold
    int mCapacity;



public:
    Xray(Sudoku* sudoku); // Add width and height parameters
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode);
};

#endif //PROJECT1_SUDOKULIB_XRAY_H
