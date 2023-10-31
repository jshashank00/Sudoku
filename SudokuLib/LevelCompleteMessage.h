/**
 * @file LevelCompleteMessage.h
 * @author jbrown
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_LEVELCOMPLETEMESSAGE_H
#define PROJECT1_SUDOKULIB_LEVELCOMPLETEMESSAGE_H
#include "Xray.h"
//#include "Sudoku.h"
//#include "Item.h"
class Sudoku;
class LevelCompleteMessage
{
private:
    Sudoku *mSudoku;
    /// Current time
    time_t mStartTime;
    time_t mNow = time(0);
    bool showMessage = false;
    std::shared_ptr<Xray> mXray;

public:
    bool GetMessage() {return showMessage;}
    LevelCompleteMessage(Sudoku *sudoku);
    void MessageTimer();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

public:

};

#endif //PROJECT1_SUDOKULIB_LEVELCOMPLETEMESSAGE_H
