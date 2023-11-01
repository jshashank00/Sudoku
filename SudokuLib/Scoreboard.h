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

    time_t mStartTime; /// >Member variable to store the level start time

public:
    Scoreboard(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    std::string GetTime();
    void StartClock();
};

#endif //PROJECT1_SUDOKULIB_SCOREBOARD_H
