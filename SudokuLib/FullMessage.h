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
class FullMessage
{
private:
    Sudoku *mSudoku;
    /// Message Board pointer
    //Xray *mXray;

public:
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    FullMessage(Sudoku *sudoku);
   //void  SetXray(Xray *xray);

    void DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_SUDOKULIB_FULLMESSAGE_H
