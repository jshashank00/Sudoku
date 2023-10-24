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
    int mValue;

public:
    Given(Sudoku *sudoku, const wxString &filename);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight);
};

#endif //PROJECT1_SUDOKULIB_GIVEN_H
