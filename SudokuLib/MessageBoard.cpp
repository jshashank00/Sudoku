/**
 * @file MessageBoard.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "MessageBoard.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Constructor
 * @param sudoku The game the scoreboard is in
 */
MessageBoard::MessageBoard(Sudoku *sudoku) : Item(sudoku)
{
}

/**
 * Draw the scoreboard
 * @param dc Device context to draw on
 */
void MessageBoard::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    time_t current = time(0);

    double diff = difftime(current, now);

    if (diff <= 3)
    {
        // Set the font and color for the text
        wxFont font(wxSize(0, 24), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        graphics->SetFont(font, *wxBLACK); // Set the text color to black

        // Draw the white message board
        graphics->SetBrush(*wxWHITE_BRUSH);

        int boardWidth = 400; // Adjust to your desired width
        int boardHeight = 180; // Adjust to your desired height
        int boardX = (width - boardWidth) / 2; // Center horizontally
        int boardY = (height - boardHeight) / 2; // Center vertically

        graphics->DrawRectangle(boardX, boardY, boardWidth, boardHeight);

        // Draw "Level 1" message in green
        font = wxFont(wxSize(60, 60), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        graphics->SetFont(font, *wxGREEN); // Set the text color to green
        wxString levelMessage = "Level 1";
        double levelTextWidth, levelTextHeight;
        graphics->GetTextExtent(levelMessage, &levelTextWidth, &levelTextHeight);
        graphics->DrawText(levelMessage, boardX + (boardWidth - levelTextWidth) / 2, boardY);

        // Draw the additional messages in black
        font = wxFont(wxSize(30, 30), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
        graphics->SetFont(font, *wxBLACK);

        wxString messages[3] = { "space: Eat", "0-8: Regurgitate", "B: Headbutt" };
        boardY += levelTextHeight; // Move below "Level 1"
        for (const wxString& msg : messages)
        {
            graphics->GetTextExtent(msg, &levelTextWidth, &levelTextHeight);
            graphics->DrawText(msg, boardX + (boardWidth - levelTextWidth) / 2, boardY);
            boardY += levelTextHeight;
        }
    }
}










