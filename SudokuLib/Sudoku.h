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

public:
    Sudoku();
    std::shared_ptr<Item> HitTest(int x, int y);
    void OnDraw(wxDC *dc);
    void Add(std::shared_ptr<Item> item);
    void Clear();
    void Load(const wxString &filename);
    void XmlItem(wxXmlNode *node);
    void XmlDeclaration(wxXmlNode *node);
    /**
     * getter for mItems
     * @return list of items in game
     */
    const std::vector<std::shared_ptr<Item>>& GetItems() const;
    void Update(double elapsed);
};

#endif //PROJECT1_SUDOKULIB_SUDOKU_H
