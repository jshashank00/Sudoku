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

public:
    Container(Sudoku* sudoku);
    void XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
    void XmlLoadFront(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
};

#endif //PROJECT1_SUDOKULIB_CONTAINER_H
