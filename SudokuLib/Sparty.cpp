/**
 * @file Sparty.cpp
 * @author Tess Murphy
 */

#include "pch.h"
#include "Sparty.h"

using namespace std;

/// Character speed in pixels per second
const double MaxSpeed = 400.00;

/// The time for an eating cycles in seconds
const double EatingTime = 0.5;

/// The time for a headbutt cycle in seconds
const double HeadbuttTime = 0.5;

/// Sparty filename
const wstring SpartyImageName = L"images/sparty-1.png";

/**
 * Constructor
 * @param sudoku The sudoku game we are in
 * @param filename Filename for the image we use
 */
Sparty::Sparty(Sudoku *sudoku) :
    Item(sudoku, SpartyImageName)
{
}