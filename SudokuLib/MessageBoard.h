/**
 * @file MessageBoard.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_MESSAGEBOARD_H
#define PROJECT1_SUDOKULIB_MESSAGEBOARD_H

#include "Xray.h"
//#include "Sudoku.h"
//#include "Item.h"
class Sudoku;
class MessageBoard {
private:
    Sudoku *mSudoku;
    /// Current time
    time_t mStartTime;
    time_t mNow = time(0);
    bool showMessage = false;
    std::shared_ptr<Xray> mXray;
    wxString mLevelToLoad;

public:
    bool GetMessage() {return showMessage;}
    MessageBoard(Sudoku *sudoku);
    void MessageTimer();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height, wxString levelMessage);
};

#endif //PROJECT1_SUDOKULIB_MESSAGEBOARD_H
