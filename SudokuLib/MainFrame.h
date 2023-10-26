/**
 * @file MainFrame.h
 * @author Shashank Jayaram
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_SUDOKULIB_MAINFRAME_H
#define PROJECT1_SUDOKULIB_MAINFRAME_H

class SudokuView;


class MainFrame : public wxFrame {
private:
    SudokuView *mSudokuView;
public:
    void Initialize();

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnClose(wxCloseEvent &event);
};

#endif //PROJECT1_SUDOKULIB_MAINFRAME_H
