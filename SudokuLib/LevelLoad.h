/**
 * @file LevelLoad.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_LEVELLOAD_H
#define PROJECT1_SUDOKULIB_LEVELLOAD_H

#include "Sudoku.h"
#include "Container.h"
#include <map>
#include <string>

class LevelLoad
{
private:
    Sudoku *mSudoku = nullptr; ///< the sudoku game we are in
    double mWidth; ///< the width of the playing area
    double mHeight; ///< the height of the playing area
    double mTileWidth; ///< the width of the tile
    double mTileHeight; ///< the width of the playing area
    int mCol; ///< top left cell of the grid
    int mRow; ///< the top left cell of the grid
    wxString mSolution; ///< the solution

    wxString mBackgroundImage; ///<background file image name

    double mPixelWidth;
    double mPixelHeight;

    ///Initialize the map id->DeclarationObject
    std::map <wxString, wxXmlNode*> mMap;

    ///List of containers
    std::vector<std::shared_ptr<Container>> mContainers;

public:
    LevelLoad(const wxString &filename, Sudoku * sudoku);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    void XmlGame(wxXmlNode *node);
    void XmlContainerItem(wxXmlNode *node);
    void XmlContainerDec(wxXmlNode *node);

    //wxString GetBackgroundImage() { return mBackgroundImage; }

    int PixelWidth() { return mWidth * mTileWidth; }
    int PixelHeight() { return mHeight * mTileHeight; }

    int Column() {return mCol;}
    int Row() {return mRow;}
    wxString Solution() {return mSolution;}

    /**
    double GetWidth() { return mWidth; }
    double GetHeight() { return mHeight; }
    double GetTileWidth() { return mTileWidth; }
    double GetTileHeight() { return mTileHeight; }
     */
    const std::vector<std::shared_ptr<Container>> &GetContainers() const;
};

#endif //PROJECT1_SUDOKULIB_LEVELLOAD_H
