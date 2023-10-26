/**
 * @file MessageBoard.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_MESSAGEBOARD_H
#define PROJECT1_SUDOKULIB_MESSAGEBOARD_H

//#include "Sudoku.h"
#include "Item.h"

class MessageBoard {
private:
    /// Current time
    time_t mStartTime;
    time_t mNow = time(0);

public:
    MessageBoard(Sudoku *sudoku);
    void MessageTimer();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

};

#endif //PROJECT1_SUDOKULIB_MESSAGEBOARD_H
