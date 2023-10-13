/**
 * @file Sudoku.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_SUDOKU_H
#define PROJECT1_SUDOKULIB_SUDOKU_H

#include "Item.h"

class Sudoku {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All the items in our game
    std::vector<std::shared_ptr<Item>> mItems;

public:
    Sudoku();
    std::shared_ptr<Item> HitTest(int x, int y);
    void OnDraw(wxDC *dc);
    void Add(std::shared_ptr<Item> item);
    void Clear();
    void Load(const wxString &filename);
    void XmlItem(wxXmlNode *node);
};

#endif //PROJECT1_SUDOKULIB_SUDOKU_H
