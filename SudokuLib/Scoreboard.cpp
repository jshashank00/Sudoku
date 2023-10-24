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
Scoreboard::Scoreboard(Sudoku *sudoku) : Item(sudoku)
{
}

/**
 * Draw the scoreboard
 * @param dc Device context to draw on
 */
void Scoreboard::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    wxFont font(wxSize(0, ScoreboardTextSize),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxWHITE);

    static bool delayElapsed = false;
    static time_t startTime = time(0);
    time_t current = time(0);
    time_t elapsed = current - startTime;

    if (elapsed > 3 && !delayElapsed) {
        delayElapsed = true;
        startTime = current;
    }

    if (delayElapsed) {
        int minutes = elapsed / 60;
        int seconds = elapsed % 60;

        std::string timeStr = std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

        graphics->DrawText(timeStr, ScoreboardTopLeft.x, ScoreboardTopLeft.y);
    }
}




