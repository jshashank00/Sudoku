/**
 * @file SolveLoad.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SOLVELOAD_H
#define PROJECT1_SUDOKULIB_SOLVELOAD_H

#include "Sudoku.h"
#include <string>

class SolveLoad
{
private:
    Sudoku *mSudoku = nullptr; ///< the sudoku game we are in
    wxString mCol; ///< top left cell of the grid
    wxString mRow; ///< the top left cell of the grid
    wxString mSolution; ///< the solution

public:
    SolveLoad(const wxString &filename, Sudoku * sudoku);
    void XmlGame(wxXmlNode *node);

};

#endif //PROJECT1_SUDOKULIB_SOLVELOAD_H
