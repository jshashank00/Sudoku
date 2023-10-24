/**
 * @file Container.h
 * @author jbrown
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_CONTAINER_H
#define PROJECT1_SUDOKULIB_CONTAINER_H

#include "Item.h"
class Container : public Item
{
private:
    /// front image of the container
    wxString mFront;
public:
    Container(Sudoku* sudoku);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
};

#endif //PROJECT1_SUDOKULIB_CONTAINER_H
