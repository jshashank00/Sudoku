/**
 * @file Scoreboard.cpp
 * @author Lillian Yanke
 */

#include "pch.h"
#include "Scoreboard.h"
#include <ctime>
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
void Scoreboard::Draw(wxDC *dc)
{
    wxFont font(wxSize(0, ScoreboardTextSize),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);

    time_t current = time(0);
    time_t diff =  current - now;
    tm* ltm = localtime(&diff);

    string secStr = std::to_string(ltm->tm_sec);
    if (secStr.length() == 1)
    {
        secStr = "0" + secStr;
    }

    string str = std::to_string(ltm->tm_min) + ":" + secStr;


    dc->DrawText(str, 10, 10);
}

