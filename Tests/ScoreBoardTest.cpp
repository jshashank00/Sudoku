/**
 * @file ScoreBoardTest.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "Scoreboard.h"
#include "Sudoku.h"
#include <gtest/gtest.h>

class ScoreboardTest : public ::testing::Test {
protected:
    Scoreboard* scoreboard;
    Sudoku* sudoku;

    void SetUp() override {
        // Create instances of Sudoku and Scoreboard
        sudoku = new Sudoku();
        sudoku->ChooseLevel("levels/level1.xml");
        scoreboard = new Scoreboard(sudoku);
    }

    void TearDown() override {
        delete scoreboard;
        delete sudoku;
    }
};

TEST_F(ScoreboardTest, ScoreboardExists) {
    // Check if the scoreboard is not a null pointer
    EXPECT_NE(&scoreboard, nullptr);
}

TEST_F(ScoreboardTest, ScoreboardTimeIsCorrect) {
    wxString timeStr = scoreboard->GetTime();

    EXPECT_FALSE(timeStr.IsEmpty());
}


