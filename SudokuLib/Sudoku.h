/**
 * @file Sudoku.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SUDOKU_H
#define PROJECT1_SUDOKULIB_SUDOKU_H

#include "Item.h"
#include "Sparty.h"

class Sudoku {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All the items in our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Sparty for this game
    std::shared_ptr<Item> mSparty;

    double mScale = 0;
    double mXOffset = 0.0;
    double mYOffset = 0.0;

public:
    Sudoku();
    std::shared_ptr<Item> HitTest(int x, int y);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Add(std::shared_ptr<Item> item);
    void Clear();

    /**
     * getter for mItems
     * @return list of items in game
     */
    const std::vector<std::shared_ptr<Item>>& GetItems() const;
    /**
     * getter for sparty
     * @return pointer to sparty
     */
    std::shared_ptr<Item> GetSparty();

    void Update(double elapsed);

};

#endif //PROJECT1_SUDOKULIB_SUDOKU_H
