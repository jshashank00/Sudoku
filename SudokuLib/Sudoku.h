/**
 * @file Sudoku.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SUDOKU_H
#define PROJECT1_SUDOKULIB_SUDOKU_H

class Sudoku {
private:
    wxBitmap *mBackground;  ///< Background image to use

public:
    Sudoku();
    void OnDraw(wxDC *dc);

};

#endif //PROJECT1_SUDOKULIB_SUDOKU_H
