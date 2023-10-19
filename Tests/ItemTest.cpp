/**
 * @file ItemTest.cpp
 * @author Lillian Yanke
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Sudoku.h>

class ItemMock : public Item {
public:
    ItemMock(Sudoku *sudoku) : Item(sudoku) {}
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height) override {}
};

TEST(ItemTest, Construct) {
    Sudoku sudoku;
    ItemMock item(&sudoku);
}

TEST(ItemTest, GettersSetters) {
    Sudoku sudoku;
    ItemMock item(&sudoku);

    // Test initial values
    ASSERT_NEAR(0, item.GetX(), 0.0001);
    ASSERT_NEAR(0, item.GetY(), 0.001);

    // Test SetLocation, GetX and GetY
    item.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, item.GetX(), 0.001);
    ASSERT_NEAR(17.2, item.GetY(), 0.001);

    // Test a second with different values
    item.SetLocation(-72, -107);
    ASSERT_NEAR(-72, item.GetX(), 0.001);
    ASSERT_NEAR(-107, item.GetY(), 0.001);
}

TEST(ItemTest, HitTest) {
// Create an item to test
    Sudoku sudoku;
    ItemMock item(&sudoku);

    item.SetImage("images/0b.png");

// Give it a location
// Always make the numbers different, in case they are mixed up
    item.SetLocation(100, 200);

// Center of the item should be a true
    ASSERT_TRUE(item.HitTest(100, 200));

// Left of the item
    ASSERT_FALSE(item.HitTest(10, 200));

// Right of the item
    ASSERT_FALSE(item.HitTest(200, 200));

// Above the item
    ASSERT_FALSE(item.HitTest(100, 0));

// Below the item
    ASSERT_FALSE(item.HitTest(100, 300));

// On a item transparent pixel
    ASSERT_FALSE(item.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}

