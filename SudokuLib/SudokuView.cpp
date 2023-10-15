/**
 * @file SudokuView.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "SudokuView.h"
#include <wx/dcbuffer.h>
#include "Scoreboard.h"

/// Frame duration
const int FrameDuration = 30;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void SudokuView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &SudokuView::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &SudokuView::OnLeftDown, this);
    Bind(wxEVT_TIMER, &SudokuView::OnTimer, this);
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
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mSudoku.OnDraw(&dc);
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void SudokuView::OnLeftDown(wxMouseEvent &event)
{
    const std::vector<std::shared_ptr<Item>> &items = mSudoku.GetItems();

    items.front()->SetLocation(event.GetX(), event.GetY());
    Refresh();
}

