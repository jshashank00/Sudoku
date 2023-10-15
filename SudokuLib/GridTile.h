/**
 * @file GridTile.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_GRIDTILE_H
#define PROJECT1_SUDOKULIB_GRIDTILE_H

/**
 * Tile in playing area grid
 */
#include "Grid.h"
class GridTile: public Grid
{
private:
    /// member variable to keep track of column in grid
    int mCol;
    /// member variable to keep track of row in grid
    int mRow;
    /// member variable to keep track of tile width
    int mWid;
    /// member variable to keep track of tile height
    int mHit;

public:

};

#endif //PROJECT1_SUDOKULIB_GRIDTILE_H
