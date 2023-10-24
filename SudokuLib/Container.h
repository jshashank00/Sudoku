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

    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;
public:

    Container(Sudoku* sudoku);
//    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode);
};

#endif //PROJECT1_SUDOKULIB_CONTAINER_H
