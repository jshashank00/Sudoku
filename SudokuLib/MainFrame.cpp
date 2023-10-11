/**
 * @file MainFrame.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "MainFrame.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Sudoku",
           wxDefaultPosition,  wxSize( 1000,800 ));

}
