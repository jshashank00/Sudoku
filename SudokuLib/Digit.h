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
    int mValue;

public:
    Digit(Sudoku *sudoku, const wxString &filename);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight);
};

#endif //PROJECT1_SUDOKULIB_DIGIT_H
