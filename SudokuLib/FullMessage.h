/**
 * @file FullMessage.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_FULLMESSAGE_H
#define PROJECT1_SUDOKULIB_FULLMESSAGE_H
//#include "Xray.h"
class Sudoku;
/**
 * Class to display "I'm full" message
 */
class FullMessage
{
private:
    /// Game we are in
    Sudoku *mSudoku;

public:
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    FullMessage(Sudoku *sudoku);
    void DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_SUDOKULIB_FULLMESSAGE_H
