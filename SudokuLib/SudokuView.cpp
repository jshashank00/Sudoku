/**
 * @file SudokuView.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "SudokuView.h"
#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void SudokuView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &SudokuView::OnPaint, this);

}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void SudokuView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mSudoku.OnDraw(&dc);
}