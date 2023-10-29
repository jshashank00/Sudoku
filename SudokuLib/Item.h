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
    double mX = 0;
    double mY = 0;
    double mCol = 0;
    double mRow = 0;
    double mWidth; ///<Width of the image
    double mHeight; ///<Height of the image

    /// Item id
    //wxString mID;

    /// variable to show if item is in container
    bool mIsInContainer;

    /// variable to show if item is in xray
    bool mIsInXray;

//    /// Items currently in container
//    std::vector<std::shared_ptr<Item>> mContainerItemsList;
protected:


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
     */
    virtual void MouthMove() {}

    virtual void SetTargetLocation(int xLoc, int yLoc) {}

    /**
     * Handle the headbutt movement
     */
    virtual void HeadButt() {}
    //void XmlLoad(wxXmlNode *node, std::shared_ptr<Declaration> decNode);
//    virtual bool IsDigit() const {
//        return false;
//    }

    ///Easy way to tell if sparty can eat a number or not
    void SetInContainer(bool isInContainer) { mIsInContainer = isInContainer; }
    bool IsInContainer() const { return mIsInContainer; }

    ///Easy way to tell if sparty can eat a number or not
    void SetInXray(bool isInXray) { mIsInXray = isInXray; }
    bool IsInXray() const { return mIsInXray; }

    /**
     * Accept a visitor
      * @param visitor The visitor we accept
      */
    virtual void Accept(ItemVisitor* visitor) {}

    double GetCol() {return mCol;}
    double GetRow() {return mRow;}

    double GetItemWid() {return mWidth;}
    double GetItemHit() {return mHeight;}

    double GetWidth() const {

        return mWidth;
    }

    double GetHeight() const {

        return mHeight;
    }

};

#endif //PROJECT1_SUDOKULIB_ITEM_H
