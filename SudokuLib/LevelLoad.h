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
/**
 * Class for loading xml file
 */
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

    double mPixelWidth; ///< pixel height
    double mPixelHeight; ///< pixel width

    ///Initialize the map id->DeclarationObject
    std::map <wxString, wxXmlNode*> mMap;

    wxString mLevel; ///< store the extracted level

    /**
     * get number of level from level string
     * @param filename level filename
     * @return level + number
     */
    wxString ExtractLevel(const wxString &filename)
    {
        if (!filename.IsEmpty())
        {
            wxChar lastChar = filename.GetChar(filename.Length() - 5);
            wxString levelStr;
            levelStr.Append(lastChar);
            wxString level = "Level " + levelStr;
            return level;
        }
        return wxString("Unknown");
    }

public:
    LevelLoad(const wxString &filename, Sudoku * sudoku);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    void XmlGame(wxXmlNode *node);
    void XmlContainerItem(wxXmlNode *node);

    /**
     * @return width in pixels
     */
    int PixelWidth() { return mWidth * mTileWidth; }
    /**
     * @return height in pixels
     */
    int PixelHeight() { return mHeight * mTileHeight; }
    /**
     * @return column
     */
    int GetColumn() {return mCol;}
    /**
     * @return row
     */
    int GetRow() {return mRow;}
    /**
     * @return solution
     */
    wxString Solution() {return mSolution;}
    /**
     * @return tilewidth
     */
    double GetTileHeight() { return mTileHeight; }

    /**
     * @return level
     */
    wxString GetLevel() const
    {
        return mLevel;
    }

};

#endif //PROJECT1_SUDOKULIB_LEVELLOAD_H
