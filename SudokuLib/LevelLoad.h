/**
 * @file LevelLoad.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_LEVELLOAD_H
#define PROJECT1_SUDOKULIB_LEVELLOAD_H

#include "Sudoku.h"

class LevelLoad
{
private:
    Sudoku *mSudoku; ///< the sudoku game we are in
    wxString mWidth; ///< the width of the playing area
    wxString mHeight; ///< the height of the playing area
    wxString mTileWidth; ///< the width of the tile
    wxString mTileHeight; ///< the width of the playing area
    wxString mCol; ///< top left cell of the grid
    wxString mRow; ///< the top left cell of the grid
    wxString mSolution; ///< the solution

    wxString mBackground; ///<background file image name

public:
    LevelLoad(const wxString &filename);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    void XmlGame(wxXmlNode *node);
    void XmlContainer(wxXmlNode *node);

    wxString GetBackground() { return mBackground; }
};

#endif //PROJECT1_SUDOKULIB_LEVELLOAD_H
