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
    int GetValue() { return mValue; }
    Digit(Sudoku *sudoku, const wxString &filename);
    // Override IsDigit to return true for digit items
//    bool IsDigit() const override {
//        return true;
//    }
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitDigit(this); }
};

#endif //PROJECT1_SUDOKULIB_DIGIT_H
