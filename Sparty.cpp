/**
 * @file Sparty.cpp
 * @author Lillian Yanke
 */

#include "pch.h"
#include "Sparty.h"
using namespace std;

/// Sparty filename
const wstring SpartyImage = L"images/sparty-1.png";

/**
 * Constructor
 * @param sudoku The game we are in
 * @param filename Filename for the image we use
 */
Sparty::Sparty(Sudoku *sudoku, const std::wstring &filename) :
    Item(sudoku, SpartyImage)
{
}