/**
 * @file IncorrectMessage.h
 * @author Ishita Saripalle
 *
 * Declaration for incorrect sudoku
 * solution message
 */

#ifndef PROJECT1_SUDOKULIB_INCORRECTMESSAGE_H
#define PROJECT1_SUDOKULIB_INCORRECTMESSAGE_H

class Sudoku;

/**
 * Message for wrong solution
 */
class IncorrectMessage
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
    IncorrectMessage(Sudoku *sudoku);
    void MessageTimer();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

};

#endif //PROJECT1_SUDOKULIB_INCORRECTMESSAGE_H
