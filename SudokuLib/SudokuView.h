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
#include "Scoreboard.h"

class SudokuView: public wxWindow {
private:
    Sudoku mSudoku;

    /// Timer for the scoreboard
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    void OnPaint(wxPaintEvent& event);
public:
    void Initialize(wxFrame* parent);
    void OnLeftDown(wxMouseEvent &event);
    void OnTimer(wxTimerEvent &event);
    void OnSize(wxSizeEvent& event);

    void OnKey(wxKeyEvent &event);
    void Stop(){mTimer.Stop();}
};

#endif //PROJECT1_SUDOKULIB_SUDOKUVIEW_H
