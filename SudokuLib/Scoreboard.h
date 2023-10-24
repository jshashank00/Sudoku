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

    time_t gameStartTime; /// >Member variable to store the game start time

public:
    Scoreboard(Sudoku *sudoku);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

    std::string GetTime() {
        time_t rawTime;
        struct tm* timeInfo;

        // Get the current time
        time(&rawTime);
        timeInfo = localtime(&rawTime);

        int minutes = timeInfo->tm_min;
        int seconds = timeInfo->tm_sec;

        std::string timeStr = std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

        return timeStr;
    }
};

#endif //PROJECT1_SUDOKULIB_SCOREBOARD_H
