/**
 * @file SudokuView.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "ids.h"
#include "SudokuView.h"
#include "Sudoku.h"
#include <wx/dcbuffer.h>
#include "Scoreboard.h"
#include <wx/graphics.h>
#include "LevelLoad.h"

/// Frame duration
const int FrameDuration = 30;


/**
 * Initialize the sudoku view class.
 * @param parent The parent window for this class
 */
void SudokuView::Initialize(wxFrame* parent)
{
    //wxFrame *mainFrame = nullptr;
    Create(parent, wxID_ANY,
           wxDefaultPosition, wxDefaultSize,
           wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &SudokuView::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &SudokuView::OnLeftDown, this);
    Bind(wxEVT_TIMER, &SudokuView::OnTimer, this);
    Bind(wxEVT_CHAR, &SudokuView::OnKey, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SudokuView::OnLevel0, this, IDM_LEVELO);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SudokuView::OnLevel1, this, IDM_LEVEL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SudokuView::OnLevel2, this, IDM_LEVEL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SudokuView::OnLevel3, this, IDM_LEVEL3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &SudokuView::OnSolve, this, IDM_SOLVE);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
}

/**
* Event Handler for the timer message
* @param event
*/
void SudokuView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void SudokuView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mSudoku.Update(elapsed);

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc =
        std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    // Tell the game class to draw
    wxRect rect = GetRect();
    mSudoku.OnDraw(gc, rect.GetWidth(), rect.GetHeight());
}

/**
 * Virtual pixels resize
 * @param event resize
 */
void SudokuView::OnSize(wxSizeEvent& event) {
    Refresh();
    event.Skip();
}

/**
 * Handle the left mouse button down event
 * @param event left down click
 */
void SudokuView::OnLeftDown(wxMouseEvent &event)
{
    //Nothing happens while message board is visible
    if (mSudoku.IsMessageBoardVisible()) return;

    double mXOffset = mSudoku.GetXOffset();
    double mYOffset = mSudoku.GetYOffset();
    double mScale = mSudoku.GetScale();
    double mPixelWidth = mSudoku.GetPixelWidth();
    double mPixelHeight = mSudoku.GetPixelHeight();

    std::shared_ptr<Item> sparty = mSudoku.GetSparty();
    if (sparty)
    {
        int xLoc = (event.GetX() - mXOffset) / mScale;
        int yLoc = (event.GetY() - mYOffset) / mScale;

        if (xLoc >= 48 && xLoc < mPixelWidth-48 && yLoc >= 0 && yLoc < mPixelHeight)
        {
            sparty->SetTargetLocation(xLoc, yLoc);
        }
        Refresh();
    }
}

/**
 * Sparty Headbutt
 * @param event key click
 */
void SudokuView::OnKey(wxKeyEvent &event)
{
    //Nothing happens while message board is visible
    if (mSudoku.IsMessageBoardVisible()) return;

    wxChar uc = event.GetUnicodeKey();
    if (uc == 98)
    {
        std::shared_ptr<Item> sparty = mSudoku.GetSparty();
        sparty->HeadButt();
    }

    else if (uc == 32)
    {
        std::shared_ptr<Item> sparty = mSudoku.GetSparty();
        sparty->MouthMove(true);
    }
    else if(uc > 47 && uc < 58)
    {
        int digit = uc - 48;
        mSudoku.MoveDigit(digit);
        std::shared_ptr<Item> sparty = mSudoku.GetSparty();
        sparty->MouthMove(false);
        this->Refresh();
        this->Update();
        mSudoku.CheckSolution();
    }
    else if (uc == 120)
    {
        mSudoku.RevealSquare();
    }
}

/**
 * Load level 0
 * @param event level load in menu
 */
void SudokuView::OnLevel0(wxCommandEvent& event)
{
    wxString level0 = "levels/level0.xml";
    mSudoku.ChooseLevel(level0);
}

/**
 * Load level 1
 * @param event level load in menu
 */
void SudokuView::OnLevel1(wxCommandEvent& event)
{
    wxString level1 = "levels/level1.xml";
    mSudoku.ChooseLevel(level1);
}
/**
 * Load level 2
 * @param event level load in menu
 */
void SudokuView::OnLevel2(wxCommandEvent& event)
{
    wxString level2 = "levels/level2.xml";
    mSudoku.ChooseLevel(level2);
}
/**
 * Load level 3
 * @param event level load in menu
 */
void SudokuView::OnLevel3(wxCommandEvent& event)
{
    wxString level3 = "levels/level3.xml";
    mSudoku.ChooseLevel(level3);
}

/**
 * When solve button is clicked in menu
 * @param event solve in menu
 */
void SudokuView::OnSolve(wxCommandEvent& event)
{
    wxString level0 = "levels/level0.xml";
    wxString level1 = "levels/level1.xml";
    wxString level2 = "levels/level2.xml";
    wxString level3 = "levels/level3.xml";
    mSudoku.Solve(level1);
    mSudoku.CheckSolution();
}