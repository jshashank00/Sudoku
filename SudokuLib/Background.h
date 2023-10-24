/**
 * @file Background.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_BACKGROUND_H
#define PROJECT1_SUDOKULIB_BACKGROUND_H
#include "Item.h"


/**
 * Class to represent a Background
 */
class Background : public Item {
private:

/// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    double mPixelWidth;
    double mPixelHeight;
public:
    Background(Sudoku *sudoku);
    void XmlLoad(wxXmlNode *itemNode, wxXmlNode *decNode, double tileHeight);
//    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_SUDOKULIB_BACKGROUND_H
