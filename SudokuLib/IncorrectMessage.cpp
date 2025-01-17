/**
 * @file IncorrectMessage.cpp
 * @author Ishita Saripalle
 *
 * Class for incorrect sudoku
 * solution message
 */

#include "pch.h"
#include "IncorrectMessage.h"
#include <ctime>
#include <time.h>
#include "Sudoku.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Constructor
 * @param sudoku The game the scoreboard is in
 */
IncorrectMessage::IncorrectMessage(Sudoku *sudoku) : mSudoku(sudoku)
{
}

/**
 * Timer for message
 */
void IncorrectMessage::MessageTimer()
{
    mStartTime = time(0);
}

/**
 * Draw the level complete message
 * @param graphics Device context to draw on
 * @param width of image
 * @param height of image
 */
void IncorrectMessage::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    time_t current = time(0);
    time_t elapsed = current - mStartTime;

    if (elapsed <= 3)
    {
        mSudoku->SetMessageBoardVisible(true);
        // Set the font and color for the text
        wxColour darkGreen = wxColour(8, 190, 90);
        wxFont font = wxFont(wxSize(100, 100), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, darkGreen); // Set the text color to green
        wxString levelMessage = "Incorrect!";

        double levelTextWidth, levelTextHeight;
        graphics->GetTextExtent(levelMessage, &levelTextWidth, &levelTextHeight);
        graphics->DrawText(levelMessage, (width - levelTextWidth) / 2, (height - levelTextHeight) / 2);
    }
    else
    {
        mSudoku->SetMessageBoardVisible(true);
        mSudoku->ChooseLevel(mSudoku->GetSameLevel());
        MessageTimer();
    }
}