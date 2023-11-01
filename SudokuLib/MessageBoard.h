/**
 * @file MessageBoard.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_MESSAGEBOARD_H
#define PROJECT1_SUDOKULIB_MESSAGEBOARD_H

class Sudoku;
/**
 * Message for starting the level
 */
class MessageBoard {
private:
    Sudoku *mSudoku; ///< Sudoku game we are in
    time_t mStartTime;  ///< Current time
    time_t mNow = time(0); ///< time now
    bool mShowMessage = false; ///< true if message should show
    wxString mLevelToLoad; ///< level that is going to be loaded

public:
    /**
     * Getter for show message bool
     * @return show message bool
     */
    bool GetMessage() {return mShowMessage;}
    MessageBoard(Sudoku *sudoku);
    void MessageTimer();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height, wxString levelMessage);
};

#endif //PROJECT1_SUDOKULIB_MESSAGEBOARD_H
