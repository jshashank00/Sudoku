/**
 * @file XmlTest.cpp
 * @author Lillian Yanke
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <fstream>

#include <Sudoku.h>
#include <LevelLoad.h>

using namespace std;

class LevelLoadTest : public ::testing::Test {


};

TEST_F(LevelLoadTest, LoadingItems) {
    Sudoku sudoku;
    LevelLoad level("levels/level1.xml", &sudoku);
    int count = 0;
    for (std::shared_ptr<Item> item : sudoku.GetItems())
    {
        count++;
    }
    ASSERT_EQ(count, 84);

    Sudoku sudoku2;
    LevelLoad level2("levels/level2.xml", &sudoku);
    int count2 = 0;
    for (std::shared_ptr<Item> item : sudoku.GetItems())
    {
        count2++;
    }
    ASSERT_EQ(count2, 87);
}

TEST_F(LevelLoadTest, Pixels){
    Sudoku sudoku;
    LevelLoad level("levels/level1.xml", &sudoku);
    ASSERT_EQ(720, level.PixelHeight());
    ASSERT_EQ(960, level.PixelWidth());

    Sudoku sudoku2;
    LevelLoad level2("levels/level2.xml", &sudoku);
    ASSERT_EQ(960, level2.PixelHeight());
    ASSERT_EQ(1440, level2.PixelWidth());
}
