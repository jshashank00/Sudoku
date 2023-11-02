/**
 * @file TakenSquareMessage.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "TakenSquareMessage.h"

#include <time.h>
#include "Sudoku.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Message Constructor
 * @param sudoku Game we are in
 * @param x x coords of message
 * @param y y coords of message
 */
TakenSquareMessage::TakenSquareMessage(Sudoku *sudoku, double x, double y) : mSudoku(sudoku)
{
    // Initialize Y-coordinates for both messages
    mPosY = y;

}
/**
 * Timer for message
 */
void TakenSquareMessage::MessageTimer()
{
    mStartTime = time(0);
}

/**
 * Update for message
 * @param elapsed The time since the last update
 */
void TakenSquareMessage::Update(double elapsed)
{
    mPosY = mPosY - 250*elapsed;
}



/**
 * Draw the square is taken message
 * @param graphics Device context to draw on
 * @param height of message
 * @param width of message
 */
void TakenSquareMessage::DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{

    wxFont font(wxSize(0, 26), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, *wxRED);  // Set the text color to red

    // Calculate message board dimensions
    int boardWidth = 400;
    int boardHeight = 40;
    int boardX = (width - boardWidth) / 2;
    int boardY = height / 4;

    // Draw the black border
    graphics->SetPen(wxPen(*wxBLACK, 5)); // 5 is the width of the black border
    graphics->SetBrush(*wxWHITE_BRUSH);
    graphics->DrawRectangle(boardX, mPosY, boardWidth, boardHeight);

    // Draw "Something is already there!" message in red
    wxString fullMessage = "Something is already there!";
    double messageWidth, messageHeight;
    graphics->GetTextExtent(fullMessage, &messageWidth, &messageHeight);
    graphics->DrawText(fullMessage, boardX + (boardWidth - messageWidth) / 2, mPosY + 5);


}
