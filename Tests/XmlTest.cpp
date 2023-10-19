/**
 * @file XmlTest.cpp
 * @author Lillian Yanke
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Sudoku.h>
#include <LevelLoad.h>

using namespace std;

class LevelLoadTest : public ::testing::Test {

};

TEST_F(LevelLoadTest, Invalid)
{
    Sudoku sudoku;
    wxString filename = "invalid.xml";
    LevelLoad  level(filename, &sudoku);
}