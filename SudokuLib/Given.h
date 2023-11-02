/**
 * @file Given.h
 * @author Tess Murphy
 *
 * Declaration for givens
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
    /// number value of a given
    int mValue= 0;

public:
    Given(Sudoku *sudoku, const wxString &filename);
    /**
    * Given value getter
    * @return value of given
    */
    int GetValue() { return mValue; }
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitGiven(this); }
};

#endif //PROJECT1_SUDOKULIB_GIVEN_H
