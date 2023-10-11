/**
 * @file SudokuApp.cpp
 * @author shash
 */

#include "SudokuApp.h"

/**
 * Initialize the application.
 * @return
 */
bool SudokuApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;
    return true;
}