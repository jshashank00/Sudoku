/**
 * @file FullMessage.h
 * @author shash
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_FULLMESSAGE_H
#define PROJECT1_SUDOKULIB_FULLMESSAGE_H
#include "Xray.h"
class Sudoku;
class FullMessage
{
private:
    Sudoku *mSudoku;
    /// Message Board pointer
    std::shared_ptr<Xray> mXray;

public:
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    FullMessage(Sudoku *sudoku);

};

#endif //PROJECT1_SUDOKULIB_FULLMESSAGE_H
