/**
 * @file LevelCompleteMessage.cpp
 * @author jbrown
 *
 * Class for correct sudoku
 * solution message
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

/**
 * Timer for message
 */
void LevelCompleteMessage::MessageTimer()
{
    mStartTime = time(0);
}

/**
 * Draw the level complete message
 * @param graphics Device context to draw on
 * @param width of image
 * @param height of image
 */
void LevelCompleteMessage::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    time_t current = time(0);
    time_t elapsed = current - mStartTime;

    if (elapsed <= 3)
    {
        mSudoku->SetMessageBoardVisible(true);

        // Set the dark green color
        wxColour darkGreen = wxColour(8, 190, 90);

        // Set the font and color for the text
        wxFont font = wxFont(wxSize(100, 100), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD); // Use wxFONTWEIGHT_BOLD for bold
        graphics->SetFont(font, darkGreen); // Set the text color to dark green
        wxString levelMessage = "Level Complete!";

        double levelTextWidth, levelTextHeight;
        graphics->GetTextExtent(levelMessage, &levelTextWidth, &levelTextHeight);
        graphics->DrawText(levelMessage, (width - levelTextWidth) / 2, (height - levelTextHeight) / 2);
    }
    else
    {
        mSudoku->SetMessageBoardVisible(true);
        mSudoku->ChooseLevel(mSudoku->GetLevel());
        MessageTimer();
    }
}
