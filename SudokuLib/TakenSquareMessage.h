/**
 * @file TakenSquareMessage.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_TAKENSQUAREMESSAGE_H
#define PROJECT1_SUDOKULIB_TAKENSQUAREMESSAGE_H
class Sudoku;
class TakenSquareMessage
{
private:
    /// Game we are in
    Sudoku *mSudoku;
    time_t mStartTime;  ///< Current time
    time_t mNow = time(0); ///< time now
    double mPosY ; ///< Y position of message

public:

    TakenSquareMessage(Sudoku *sudoku, double x, double y);
    void MessageTimer();
    void DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Update(double elapsed);
};

#endif //PROJECT1_SUDOKULIB_TAKENSQUAREMESSAGE_H
