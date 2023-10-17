/**
 * @file MessageBoard.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_MESSAGEBOARD_H
#define PROJECT1_SUDOKULIB_MESSAGEBOARD_H

#include "Sudoku.h"

class MessageBoard : public Item
{
private:
    /// Current time
    time_t now = time(0);

public:
    MessageBoard(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

};

#endif //PROJECT1_SUDOKULIB_MESSAGEBOARD_H
