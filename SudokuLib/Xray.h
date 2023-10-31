/**
 * @file Xray.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_XRAY_H
#define PROJECT1_SUDOKULIB_XRAY_H

#include "Item.h"
//#include "MessageBoard.h"
//#include "FullMessage.h"

class Xray : public Item
{
private:

    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// capacity of numbers xray can hold
    int mCapacity = 0;

    /// numbers added to xray
    int mTotalNumbers = 0;

    ///List of items in the xray
    std::vector<std::shared_ptr<Item>> mXrayItems;


    bool showMessage = false;



public:
    Xray() = delete;

    /// Copy constructor (disabled)
    Xray(const Xray &) = delete;

    /// Assignment operator
    void operator=(const Xray &) = delete;

    std::vector<std::shared_ptr<Item>>& GetItems() { return mXrayItems; }

    Xray(Sudoku* sudoku); // Add width and height parameters
//    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight) override;
    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitXray(this); }

    bool AddItem(std::shared_ptr<Item> item);
    // A public function to check if showMessage is true
    bool ShouldShowMessage() const {
        return showMessage;
    }


    std::vector<std::shared_ptr<Item>> GetXrayItems();
    void RemoveDigit(std::shared_ptr<Item> item);
};

#endif //PROJECT1_SUDOKULIB_XRAY_H
