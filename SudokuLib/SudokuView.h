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

    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;
public:
    void Initialize(wxFrame* parent);

    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent &event);
    void OnMouseMove(wxMouseEvent &event);
};

#endif //PROJECT1_SUDOKULIB_SUDOKUVIEW_H
