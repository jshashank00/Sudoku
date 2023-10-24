/**
 * @file LevelLoad.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_LEVELLOAD_H
#define PROJECT1_SUDOKULIB_LEVELLOAD_H

#include "Sudoku.h"
#include "Declaration.h"
#include <map>
#include <string>

class LevelLoad
{
private:
    Sudoku * mSudoku = nullptr; ///< the sudoku game we are in
    wxString mWidth; ///< the width of the playing area
    wxString mHeight; ///< the height of the playing area
    wxString mTileWidth; ///< the width of the tile
    wxString mTileHeight; ///< the width of the playing area
    wxString mCol; ///< top left cell of the grid
    wxString mRow; ///< the top left cell of the grid
    wxString mSolution; ///< the solution

    wxString mBackground; ///<background file image name

    ///Initialize the map id->DeclarationObject
    //std::map <wxString, std::shared_ptr<Declaration>> mMap;
    std::map <wxString, wxXmlNode*> mMap;

public:
    LevelLoad(const wxString &filename, Sudoku * sudoku);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    void XmlGame(wxXmlNode *node);
    void XmlContainerItem(wxXmlNode *node);
    void XmlContainerDec(wxXmlNode *node);
    wxString GetBackground() { return mBackground; }
};

#endif //PROJECT1_SUDOKULIB_LEVELLOAD_H
