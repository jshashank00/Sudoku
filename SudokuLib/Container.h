/**
 * @file Container.h
 * @author jbrown
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_CONTAINER_H
#define PROJECT1_SUDOKULIB_CONTAINER_H

#include "Item.h"

/**
 * Class for a container in our game
 */
class Container : public Item
{
private:
    ///List of items in the container
    std::vector<std::shared_ptr<Item>> mContainedItems;

    /// The item image
    std::unique_ptr<wxImage> mFrontImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mFrontBitmap;


public:
    Container(Sudoku* sudoku);
    void XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
    void AddItem(std::shared_ptr<Item> item);
    std::vector<std::shared_ptr<Item>> GetContainedItems() const;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitContainer(this); }
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height) override;

    void Clear();
};

#endif //PROJECT1_SUDOKULIB_CONTAINER_H
