/**
 * @file ScoreBoardTest.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Sudoku.h"
#include <gtest/gtest.h>

class ScoreBoardTest : public::testing::Test {

};

TEST(ScoreboardTest, ScoreboardExists) {
    Sudoku sudoku;
    Scoreboard scoreboard(&sudoku);

    // Check if the scoreboard is not a null pointer
    EXPECT_NE(&scoreboard, nullptr);
}

