/**
 * @file TeamFeature.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "TeamFeature.h"
#include <wx/graphics.h>
using namespace std;

/**
 * Constructor for team feature
 * @param sudoku game we are in
 * @param filename image filename
 */
TeamFeature::TeamFeature(Sudoku *sudoku, const wxString &filename) : Item(sudoku, filename)
{
}