/**
 * @file SudokuView.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SUDOKUVIEW_H
#define PROJECT1_SUDOKULIB_SUDOKUVIEW_H

#include "Sudoku.h"

class SudokuView: public wxWindow {
private:
    Sudoku mSudoku;
    void OnPaint(wxPaintEvent& event);
public:
    void Initialize(wxFrame* parent);

};

#endif //PROJECT1_SUDOKULIB_SUDOKUVIEW_H
