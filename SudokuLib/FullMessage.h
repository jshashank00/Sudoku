/**
 * @file FullMessage.h
 * @author Shashank Jayaram
 *
 * Declaration for sparty 'I'm full' message
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
    double mPosY ; ///< Y position of message

public:
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    FullMessage(Sudoku *sudoku, double x, double y);
    void MessageTimer();
    void DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Update(double elapsed);
};

#endif //PROJECT1_SUDOKULIB_FULLMESSAGE_H
