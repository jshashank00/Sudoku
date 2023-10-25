/**
 * @file Scoreboard.h
 * @author Lillian Yanke
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SCOREBOARD_H
#define PROJECT1_SUDOKULIB_SCOREBOARD_H
#include "Item.h"

class Scoreboard //: public Item
{
private:

    time_t gameStartTime; /// >Member variable to store the game start time

public:
    Scoreboard(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    std::string GetTime();
};

#endif //PROJECT1_SUDOKULIB_SCOREBOARD_H
