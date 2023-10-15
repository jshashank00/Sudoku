/**
 * @file MainFrame.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "MainFrame.h"
#include "SudokuView.h"
#include "ids.h"

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
    auto sudokuView = new SudokuView();
    sudokuView->Initialize(this);

    // Add it to the sizer
    sizer->Add(sudokuView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );
    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto levelMenu = new wxMenu();

    fileMenu->Append(IDM_SOLVE, L"&Solve", L"Solve Sudoku");
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");


    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");
    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(levelMenu, L"&Level");
    menuBar->Append(helpMenu, L"&Help");


    levelMenu->Append(IDM_LEVELO, L"&Level 0", L"Play Level 0");
    levelMenu->Append(IDM_LEVEL1, L"&Level 1", L"Play Level 1");
    levelMenu->Append(IDM_LEVEL2, L"&Level 2", L"Play Level 2");
    levelMenu->Append(IDM_LEVEL3, L"&Level 3", L"Play Level 3");


    SetMenuBar( menuBar );
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);

}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to Sudoku!",
                 L"About Sudoku",
                 wxOK | wxICON_INFORMATION,
                 this);
}

