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
    ///List of items in the container
    std::vector<std::shared_ptr<Item>> mContainedItems;
public:
    Container(Sudoku* sudoku);
    void XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
    void XmlLoadFront(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
    void AddItem(std::shared_ptr<Item> item);
    const std::vector<std::shared_ptr<Item>> &GetContainedItems() const;
};

#endif //PROJECT1_SUDOKULIB_CONTAINER_H
