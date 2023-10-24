/**
 * @file Digit.h
 * @author Tess Murphy
 *
 * Class to represent a digit item
 */

#ifndef PROJECT1_SUDOKULIB_DIGIT_H
#define PROJECT1_SUDOKULIB_DIGIT_H

#include "Item.h"

/**
 * Class to represent a Digit Item
 */
class Digit : public Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mNumberImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mNumberBitmap;

    int mValue;

public:
    Digit(Sudoku *sudoku);
//    void Draw(std::shared_ptr<wxGraphicsContext>, int width, int height);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode);

};

#endif //PROJECT1_SUDOKULIB_DIGIT_H
