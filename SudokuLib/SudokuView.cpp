/**
 * @file SudokuView.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "SudokuView.h"
#include "Sudoku.h"
#include <wx/dcbuffer.h>
#include "Scoreboard.h"
#include <wx/graphics.h>

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
    Bind(wxEVT_CHAR, &SudokuView::OnSpace, this);
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

void SudokuView::OnSize(wxSizeEvent& event) {
    Refresh();
    event.Skip();
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void SudokuView::OnLeftDown(wxMouseEvent &event)
{
    std::shared_ptr<Item> sparty = mSudoku.GetSparty();
    if (sparty)
    {
        sparty->SetLocation(event.GetX(), event.GetY());
        Refresh();
    }
}

/**
 * Handle the sparty mouth move
 * @param event
 */
void SudokuView::OnSpace(wxKeyEvent &event)
{
    wxChar uc = event.GetUnicodeKey();
    if (uc == 32)
    {
        std::shared_ptr<Item> sparty = mSudoku.GetSparty();
    }
}