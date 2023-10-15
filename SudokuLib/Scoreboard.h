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
    /// Current time
    time_t now = time(0);

public:
    Scoreboard(Sudoku *sudoku);
    void Draw(wxDC *dc);
};

#endif //PROJECT1_SUDOKULIB_SCOREBOARD_H
