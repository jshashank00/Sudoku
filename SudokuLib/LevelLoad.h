/**
 * @file LevelLoad.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_LEVELLOAD_H
#define PROJECT1_SUDOKULIB_LEVELLOAD_H

#include "Sudoku.h"
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
    wxString mCol; ///< top left cell of the grid
    wxString mRow; ///< the top left cell of the grid
    wxString mSolution; ///< the solution

    wxString mBackgroundImage; ///<background file image name

    double mPixelWidth;
    double mPixelHeight;

    ///Initialize the map id->DeclarationObject
    std::map <wxString, wxXmlNode*> mMap;

public:
    LevelLoad(const wxString &filename, Sudoku * sudoku);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    void XmlGame(wxXmlNode *node);
    void XmlContainerItem(wxXmlNode *node);
    void XmlContainerDec(wxXmlNode *node);

    //wxString GetBackgroundImage() { return mBackgroundImage; }

    int PixelWidth() { return mWidth * mTileWidth;; }
    int PixelHeight() { return mHeight * mTileHeight;; }
    /**
    double GetWidth() { return mWidth; }
    double GetHeight() { return mHeight; }
    double GetTileWidth() { return mTileWidth; }
    double GetTileHeight() { return mTileHeight; }
     */
};

#endif //PROJECT1_SUDOKULIB_LEVELLOAD_H
