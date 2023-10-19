/**
 * @file Scoreboard.h
 * @author Lillian Yanke
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SCOREBOARD_H
#define PROJECT1_SUDOKULIB_SCOREBOARD_H
#include "Item.h"

class Scoreboard : public Item
{
private:

public:
    Scoreboard(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
};

#endif //PROJECT1_SUDOKULIB_SCOREBOARD_H
