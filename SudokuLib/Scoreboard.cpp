/**
 * @file Scoreboard.cpp
 * @author Lillian Yanke
 */

#include "pch.h"
#include "Scoreboard.h"
#include <ctime>
#include <wx/graphics.h>
using namespace std;

/// Size of the scoreboard text in virtual pixels
const int ScoreboardTextSize = 64;

/// Top left corner of the scoreboard in virtual pixels
const wxPoint ScoreboardTopLeft(10, 10);

/**
 * Constructor
 * @param sudoku The game the scoreboard is in
 */
Scoreboard::Scoreboard(Sudoku *sudoku) //: Item(sudoku)
{
}

/**
 * Restart the clock for each level
 */
void Scoreboard::StartClock()
{
    mStartTime = time(0);
};

/**
 * Draw the scoreboard
 * @param graphics Device context to draw on
 * @param height of message
 * @param width of message
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    wxFont font(wxSize(0, ScoreboardTextSize),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxWHITE);

    static bool delayElapsed = false;
    time_t current = time(0);
    time_t elapsed = current - mStartTime;

    if (elapsed <= 3 && delayElapsed)
    {
        delayElapsed = true;
        mStartTime = current;
    }

    if (elapsed > 3 && !delayElapsed)
    {
        int minutes = elapsed / 60;
        int seconds = elapsed % 60;

        if (elapsed > 3)
        {
            seconds -= 4;
        }

        if (seconds < 0)
        {
            seconds += 60;
            minutes--;
        }

        std::string timeStr = std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

        graphics->DrawText(timeStr, ScoreboardTopLeft.x, ScoreboardTopLeft.y);
    }
}

/**
 * Get current clock time
 * return string of clock time
 */
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


