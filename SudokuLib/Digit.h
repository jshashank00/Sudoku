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
    /// number value of a digit
    int mValue = 0;

public:
    /**
     * Digit Value Getter
     * @return digit value
     */
    int GetValue() { return mValue; }
    Digit(Sudoku *sudoku, const wxString &filename);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitDigit(this); }
};

#endif //PROJECT1_SUDOKULIB_DIGIT_H
