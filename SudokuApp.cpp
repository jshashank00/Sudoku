/**
 * @file SudokuApp.cpp
 * @author shash
 */

#include "pch.h"
#include "SudokuApp.h"
#include <MainFrame.h>


/**
 * Initialize the application.
 * @return
 */
bool SudokuApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;


}