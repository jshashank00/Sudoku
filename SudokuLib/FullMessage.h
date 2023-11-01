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
    time_t mStartTime;  ///< Current time
    time_t mNow = time(0); ///< time now
    int messageY ;
    int takenSquareMessageY;

public:
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    FullMessage(Sudoku *sudoku);
    void MessageTimer();
    void DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_SUDOKULIB_FULLMESSAGE_H
