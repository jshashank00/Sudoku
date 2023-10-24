/**
 * @file SudokuTest.cpp
 * @author Lillian Yanke
 */

#include <pch.h>
#include <gtest/gtest.h>
#include <Sudoku.h>
#include <Item.h>
#include <Digit.h>
#include <Given.h>

using namespace std;

class SudokuTest : public::testing::Test {
protected:
    /**
    *  Populate an aquarium with all types
    */
    void PopulateDiffTypes(Sudoku *sudoku)
    {

        auto sparty = make_shared<Sparty>(sudoku);
        sudoku->Add(sparty);
        sparty->SetImage("images/sparty-1.png");
        sparty->SetLocation(100, 200);

        auto digit = make_shared<Digit>(sudoku, "images/0r.png");
        sudoku->Add(digit);
        digit->SetLocation(400, 400);

        auto given = make_shared<Given>(sudoku, "images/0b.png");
        sudoku->Add(given);
        given->SetLocation(600, 100);

    }
};

TEST_F(SudokuTest, Construct){
    Sudoku sudoku;
}

TEST_F(SudokuTest, Clear)
{
    // Create an aquarium
    Sudoku sudoku;

    // Populate aquarium
    PopulateDiffTypes(&sudoku);

    sudoku.Clear();

    // Assert empty aquarium
    ASSERT_EQ(sudoku.HitTest(100,200), nullptr);
    ASSERT_EQ(sudoku.HitTest(400,400), nullptr);
    ASSERT_EQ(sudoku.HitTest(600,100), nullptr);
}