/**
 * @file FullMessage.cpp
 * @author shash
 */
#include "pch.h"
#include "FullMessage.h"
#include "MessageBoard.h"
#include <ctime>
#include <time.h>
#include "Sudoku.h"
#include "Xray.h"
#include <wx/graphics.h>

using namespace std;

FullMessage::FullMessage(Sudoku *sudoku){

}

/**
 * Draw the I'm full message
 * @param dc Device context to draw on
 */
void FullMessage::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Set the font and color for the text
    if(mXray->ShouldShowMessage())
    {
        wxFont font(wxSize(0, 26), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, *wxRED);  // Set the text color to red

        // Calculate message board dimensions
        int boardWidth = 200;
        int boardHeight = 40;
        int boardX = (width - boardWidth) / 2;
        int boardY = height / 4;

        // Draw the white message board
        graphics->SetBrush(*wxWHITE_BRUSH);
        graphics->DrawRectangle(boardX, boardY, boardWidth, boardHeight);

        // Draw "I'm Full!" message in red
        wxString fullMessage = "I'm Full!";
        double messageWidth, messageHeight;
        graphics->GetTextExtent(fullMessage, &messageWidth, &messageHeight);
        graphics->DrawText(fullMessage, boardX + (boardWidth - messageWidth) / 2, boardY + 5);
    }
}