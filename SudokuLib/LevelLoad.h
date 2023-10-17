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
    /// the sudoku game we are in
    Sudoku mSudoku;
    wxString mWidth;
    wxString mHeight;
    wxString mTileWidth;
    wxString mTileHeight;

public:
    void Load(const wxString &filename);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    void XmlGame(wxXmlNode *node);
    void XmlContainer(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_LEVELLOAD_H
