/**
 * @file SudokuTest.cpp
 * @author Lillian Yanke
 */

#include <pch.h>
#include <gtest/gtest.h>
#include <Sudoku.h>
#include <Item.h>
using namespace std;

class SudokuTest : public::testing::Test {

};

TEST_F(SudokuTest, Construct){
    Sudoku sudoku;
}
