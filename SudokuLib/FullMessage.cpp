/**
 * @file FullMessage.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "FullMessage.h"
#include "MessageBoard.h"
#include <ctime>
#include <time.h>
#include "Sudoku.h"
#include <wx/graphics.h>

using namespace std;

/**
 * Message Constructor
 * @param sudoku Game we are in
 */
FullMessage::FullMessage(Sudoku *sudoku, double x, double y) : mSudoku(sudoku)
{
    // Initialize Y-coordinates for both messages
    messageY = y;
    takenSquareMessageY = 0;
}
/**
 * Timer for message
 */
void FullMessage::MessageTimer()
{
    mStartTime = time(0);
}

/**
 * Update for message
 */
void FullMessage::Update(double elapsed)
{
    messageY = messageY - 250*elapsed;
}

/**
 * Draw the I'm full message
 * @param graphics Device context to draw on
 * @param width of message
 * @param height of message
 */
void FullMessage::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
    // Set the font and color for the text
    //mXray->ShouldShowMessage();
    //if(mXray->ShouldShowMessage())
//    time_t current = time(0);
//    time_t elapsed = current - mStartTime;
//
//    if (elapsed <= 3)
//    {
        //mSudoku->SetMessageBoardVisible(true);
        wxFont font(wxSize(0, 26), wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
        graphics->SetFont(font, *wxRED);  // Set the text color to red

        // Calculate message board dimensions
        int boardWidth = 200;
        int boardHeight = 40;
        int boardX = (width - boardWidth) / 2;
        int boardY = height / 4;

        // Draw the black border
        graphics->SetPen(wxPen(*wxBLACK, 5)); // 1 is the width of the black border
        graphics->SetBrush(*wxWHITE_BRUSH);
        graphics->DrawRectangle(boardX, messageY, boardWidth, boardHeight);

        // Draw "I'm Full!" message in red
        wxString fullMessage = "I'm Full!";
        double messageWidth, messageHeight;
        graphics->GetTextExtent(fullMessage, &messageWidth, &messageHeight);
        graphics->DrawText(fullMessage, boardX + (boardWidth - messageWidth) / 2, messageY + 5);
    }
//    if(elapsed > 3 && !delayElapsed)
//    {
//        mSudoku->SetMessageBoardVisible(false);
//    }

//    else{
//        //mSudoku->ChooseLevel(mSudoku->GetLevel());
//        //MessageTimer();
//        mSudoku->SetGameOver(false);
//    }


/**
 * Draw the square is taken message
 * @param graphics Device context to draw on
 * @param height of message
 * @param width of message
 */
void FullMessage::DrawTakenSquare(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
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
        graphics->DrawRectangle(boardX, messageY, boardWidth, boardHeight);

        // Draw "Something is already there!" message in red
        wxString fullMessage = "Something is already there!";
        double messageWidth, messageHeight;
        graphics->GetTextExtent(fullMessage, &messageWidth, &messageHeight);
        graphics->DrawText(fullMessage, boardX + (boardWidth - messageWidth) / 2, messageY + 5);


}
