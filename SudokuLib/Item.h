/**
 * @file Item.h
 * @author Lillian Yanke
 *
 * Base class for any item in our game
 */

#ifndef PROJECT1_SUDOKULIB_ITEM_H
#define PROJECT1_SUDOKULIB_ITEM_H
#include <memory>

#include <wx/xml/xml.h>
#include "ItemVisitor.h"
class Sudoku;

/**
 * Base class for any item in our game
 */
class Item
{
private:
    /// The item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap to display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

    /// The game the item is in
    Sudoku *mSudoku;

    /// Item location
    double mX = 0; ///< x location of item
    double mY = 0; ///< y location of item
    double mCol = 0; ///< col location of item
    double mRow = 0; ///< row location of item
    double mWidth = 0; ///<Width of the image
    double mHeight = 0; ///<Height of the image

    /// variable to show if item is in container
    bool mIsInContainer = false;

    /// variable to show if item is in xray
    bool mIsInXray = false;

public:
    void SetImage(const wxString &filename);

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * The Game
     * @return mSudoku
     */
    Sudoku * GetSudoku() {return mSudoku;}

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    /**
    * Set the item location
    * @param x X location in pixels
    * @param y Y location in pixels
    */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual bool HitTest(int x, int y);
    virtual void XmlLoad(wxXmlNode *node, wxXmlNode *decNode, double tileHeight);

    /// Constructor
    Item(Sudoku *sudoku, const wxString &filename);

    ///Constructor
    Item(Sudoku *sudoku);

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) {}

    /**
     * Handle the Mouth movement
     * @param moving true if moving, false otherwise
     */
    virtual void MouthMove(bool moving) {}

    /**
     * set target location x and y
     * @param xLoc x location
     * @param yLoc y location
     */
    virtual void SetTargetLocation(int xLoc, int yLoc) {}

    /**
     * Handle the headbutt movement
     */
    virtual void HeadButt() {}

    /**
     * Set in container to true or false
     * @param isInContainer true if item in container
     */
    void SetInContainer(bool isInContainer) { mIsInContainer = isInContainer; }
    /**
     * InContainer getter
     * @return true if in container
     */
    bool IsInContainer() const { return mIsInContainer; }

    /**
     * Set in xray to true or false
     * @param isInXray true if item in xray
     */
    void SetInXray(bool isInXray) { mIsInXray = isInXray; }
    /**
     * InXray getter
     * @return true if in xray
     */
    bool IsInXray() const { return mIsInXray; }

    /**
     * Accept a visitor
      * @param visitor The visitor we accept
      */
    virtual void Accept(ItemVisitor* visitor) {}

    /**
     * @return column
     */
    double GetCol() {return mCol;}

    /**
     * @return row
     */
    double GetRow() {return mRow;}

    bool ContainerHitTest(int x, int y);

    /**
     * @return width
     */
    double GetWidth() const {

        return mWidth;
    }
    /**
     * @return height
     */
    double GetHeight() const {

        return mHeight;
    }

};

#endif //PROJECT1_SUDOKULIB_ITEM_H
