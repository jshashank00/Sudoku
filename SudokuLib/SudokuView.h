/**
 * @file SudokuView.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SUDOKUVIEW_H
#define PROJECT1_SUDOKULIB_SUDOKUVIEW_H

#include "Sudoku.h"
#include "Sparty.h"

class SudokuView: public wxWindow {
private:
    Sudoku mSudoku;
    void OnPaint(wxPaintEvent& event);
public:
    void Initialize(wxFrame* parent);
    void OnLeftDown(wxMouseEvent &event);
    void OnTimer(wxTimerEvent &event);
    void OnSize(wxSizeEvent& event);

};

#endif //PROJECT1_SUDOKULIB_SUDOKUVIEW_H
