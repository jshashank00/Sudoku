/**
 * @file LevelCompleteMessage.h
 * @author jbrown
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_LEVELCOMPLETEMESSAGE_H
#define PROJECT1_SUDOKULIB_LEVELCOMPLETEMESSAGE_H
//#include "Xray.h"
//#include "Sudoku.h"
//#include "Item.h"
class Sudoku;
/**
 * Message for completing the level
 */
class LevelCompleteMessage
{
private:
    /// Game we are in
    Sudoku *mSudoku;
    /// Current time
    time_t mStartTime;
    /// false if message shouldn't show
    bool showMessage = false;

public:
    /**
    * @return show message bool
    */
    bool GetMessage() {return showMessage;}
    LevelCompleteMessage(Sudoku *sudoku);
    void MessageTimer();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

};

#endif //PROJECT1_SUDOKULIB_LEVELCOMPLETEMESSAGE_H
