/**
 * @file MainFrame.h
 * @author Ishita Saripalle
 *
 * The top-level (main) frame of the application
 */

#ifndef PROJECT1_SUDOKULIB_MAINFRAME_H
#define PROJECT1_SUDOKULIB_MAINFRAME_H


class MainFrame : public wxFrame {
private:

public:
    void Initialize();

    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
};

#endif //PROJECT1_SUDOKULIB_MAINFRAME_H
