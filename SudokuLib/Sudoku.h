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
#include "Scoreboard.h"
#include "MessageBoard.h"
#include <random>

class Sudoku {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All the items in our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Sparty for this game
    std::shared_ptr<Item> mSparty;
    /// Xray for this game
    std::shared_ptr<Xray> mXray;


    std::shared_ptr<Scoreboard> mScoreboard;

    /// Message Board pointer
    std::shared_ptr<MessageBoard> mMessageBoard;

    double mScale = 0;
    double mXOffset = 0.0;
    double mYOffset = 0.0;

    double mLocX;
    double mLocY;
    wxStopWatch mStopWatch;
    double mElapsedTime = 0.0; // To track the elapsed time
    double mTime = 0.0;
    double mSpartyTargetX; // Store the target X coordinate for Sparty
    double mSpartyTargetY; // Store the target Y coordinate for Sparty

    int mPixelWidth;
    int mPixelHeight;
    int mColumn;
    int mRow;
    wxString mSolution;


    std::shared_ptr<wxGraphicsContext> mGraphics;
    int mWidth;
    int mHeight;
    /// Random number generator
    std::mt19937 mRandom;

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

    double GetSpartyTargetX() const {
        return mSpartyTargetX;
    }

    double GetSpartyTargetY() const {
        return mSpartyTargetY;
    }

    void Update(double elapsed);

    void SetLocation(wxMouseEvent &event);
    void SetSparty(std::shared_ptr<Item> sparty);
    void SetPixelWidth(int wid);
    void SetPixelHeight(int height);
    void ChooseLevel(wxString level);
    void Solve(wxString solve);
    double GetXOffset() const { return mXOffset; }
    double GetYOffset() const { return mYOffset; }
    double GetScale() const { return mScale; }
    double GetPixelWidth() const { return mPixelWidth; }
    double GetPixelHeight() const { return mPixelHeight; }
    void AddFront(std::shared_ptr<Item> item);
    bool Eater(Item *eater);
    bool HeadbuttContainer(Item *headbuttItem);
    void Accept(ItemVisitor *visitor);
    /**
 * Get the random number generator
 * @return Pointer to the random number generator
 */
    std::mt19937 &GetRandom() {return mRandom;}

    bool TakenSquare(int x, int y);
    void SetXray(std::shared_ptr<Xray> xray);
    void MoveDigit(int digit, int x, int y);
};

#endif //PROJECT1_SUDOKULIB_SUDOKU_H
