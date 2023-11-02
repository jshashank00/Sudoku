/**
 * @file Scoreboard.h
 * @author Lillian Yanke
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SCOREBOARD_H
#define PROJECT1_SUDOKULIB_SCOREBOARD_H
#include "Item.h"
/**
 * Scoreboard class
 */
class Scoreboard
{
private:

    time_t mStartTime; ///< Member variable to store the level start time

    bool mPaused = false; ///< Paused variable

    std::string mTimerString; ///< time as a string
public:
    Scoreboard(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    /**
     * Get current clock time
     * @return string of clock time
     */
    wxString GetTime();
    void StartClock();
    void StopClock();
};

#endif //PROJECT1_SUDOKULIB_SCOREBOARD_H
