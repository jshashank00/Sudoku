/**
 * @file LevelCompleteMessage.cpp
 * @author jbrown
 */
#include "pch.h"
#include "LevelCompleteMessage.h"
#include <ctime>
#include <time.h>
#include "Sudoku.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Constructor
 * @param sudoku The game the scoreboard is in
 */
LevelCompleteMessage::LevelCompleteMessage(Sudoku *sudoku) : mSudoku(sudoku)
{
}

void LevelCompleteMessage::MessageTimer()
{
    mStartTime = time(0);
}

/**
 * Draw the scoreboard
 * @param dc Device context to draw on
 */
void LevelCompleteMessage::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    static bool delayElapsed = false;
    time_t current = time(0);
    time_t elapsed = current - mStartTime;

    if (elapsed <= 3 && !delayElapsed)
    {
        // Set the font and color for the text
        wxFont font = wxFont(wxSize(60, 60), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        graphics->SetFont(font, *wxGREEN); // Set the text color to green
        wxString levelMessage = "Level Complete!";

        double levelTextWidth, levelTextHeight;
        graphics->GetTextExtent(levelMessage, &levelTextWidth, &levelTextHeight);
        graphics->DrawText(levelMessage, (width - levelTextWidth) / 2, (height - levelTextHeight) / 2);
    }
    else
    {
        delayElapsed = true;
        mStartTime = current;
    }
}