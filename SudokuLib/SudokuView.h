/**
 * @file SudokuView.h
 * @author Ishita Saripalle
 *
 * Declaraton of view
 */

#ifndef PROJECT1_SUDOKULIB_SUDOKUVIEW_H
#define PROJECT1_SUDOKULIB_SUDOKUVIEW_H
/**
 * View class for our sudoku game
 */
#include "Sudoku.h"
#include "Sparty.h"
#include "Scoreboard.h"

class SudokuView: public wxWindow {
private:
    /// sudoku game we are in
    Sudoku mSudoku;

    /// Timer for the scoreboard
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    std::shared_ptr<wxGraphicsContext> mGc; ///< graphics context

    void OnPaint(wxPaintEvent& event);

public:
    void Initialize(wxFrame* parent);
    void OnLeftDown(wxMouseEvent &event);
    void OnTimer(wxTimerEvent &event);
    void OnSize(wxSizeEvent& event);

    void OnKey(wxKeyEvent &event);
    /**
     * Stop the timer
     */
    void Stop(){mTimer.Stop();}

    void OnLevel0(wxCommandEvent& event);
    void OnLevel1(wxCommandEvent& event);
    void OnLevel2(wxCommandEvent& event);
    void OnLevel3(wxCommandEvent& event);
    void OnSolve(wxCommandEvent& event);
};

#endif //PROJECT1_SUDOKULIB_SUDOKUVIEW_H
