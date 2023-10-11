/**
 * @file MainFrame.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "MainFrame.h"
#include "SudokuView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Action Sudoku",
           wxDefaultPosition,  wxSize( 950,750 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto aquariumView = new SudokuView();
    aquariumView->Initialize(this);

    // Add it to the sizer
    sizer->Add(aquariumView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

}
