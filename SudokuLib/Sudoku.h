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
#include "FullMessage.h"
#include "LevelCompleteMessage.h"
#include <random>
/**
 * Class for sudoku game
 */
class Sudoku {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

    /// All the items in our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Sparty for this game
    std::shared_ptr<Item> mSparty;

    /// Scoreboard for the game
    std::shared_ptr<Scoreboard> mScoreboard;

    /// Message Board pointer
    std::shared_ptr<MessageBoard> mMessageBoard;
    /// Message Board pointer
    std::shared_ptr<FullMessage> mFullMessage;
    /// Message Board pointer
    std::shared_ptr<LevelCompleteMessage> mLevelCompleteMessage;


    double mScale = 0; ///< scale for the game
    double mXOffset = 0.0; ///< X offset
    double mYOffset = 0.0; ///< Y offset

    double mLocX = 0; ///< Location X
    double mLocY = 0; ///< Location Y
    wxStopWatch mStopWatch; ///< Stopwatch for scoreboard
    double mElapsedTime = 0.0; ///< To track the elapsed time
    double mTime = 0.0; ///< time elapsed
    double mSpartyTargetX = 0; ///< Store the target X coordinate for Sparty
    double mSpartyTargetY = 0; ///< Store the target Y coordinate for Sparty

    int mPixelWidth = 0; ///< width in pixels
    int mPixelHeight = 0; ///< height in pixels
    int mColumn = 0; ///< column
    int mRow = 0; ///< row
    int mTileHeight = 0; ///< height of the tiles
    wxString mSolution; ///< solution to the game

    std::shared_ptr<wxGraphicsContext> mGraphics; ///< graphics context of the game
    int mWidth = 0; ///< width
    int mHeight = 0; ///< height
    /// Random number generator
    std::mt19937 mRandom;

    /// Holds the solution
    std::vector<int> mVectorSolution;

    /// flag for message board displayed
    bool mMessageBoardVisible;

    int mGridXLeft; ///< X location of the left of the grid
    int mGridXRight; ///< X location of the right of the grid
    int mGridYTop; ///< Y location of the top of the grid
    int mGridYBot; ///< Y location of the bottom of the grid
    bool mGameOver = false; ///< true if game is over
    bool mBoxFull = false; ///< true if grid square has a number

    bool mComplete = false; ///< true if grid is full

    wxString mLevelMessage; ///< message before each level

    wxString mNextLevel; ///< next level to load

public:
    Sudoku();
    std::shared_ptr<Item> HitTest(int x, int y);
    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Add(std::shared_ptr<Item> item);
    void Clear();
    void SetGameOver(bool over){mGameOver = over;}
    void BoxFull(bool full){mBoxFull = full;}

    /**
     * getter for the next level in the game
     * @return next level
     */
    wxString GetLevel() const
    {
        return mNextLevel;
    }

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
    /**
     * getter for sparty target x
     * @return int of sparty target y
     */
    double GetSpartyTargetX() const {
        return mSpartyTargetX;
    }
    /**
     * getter for sparty target y
     * @return int of sparty target y
     */
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
    /**
     * getter for offsetx
     * @return int offsetx
     */
    double GetXOffset() const { return mXOffset; }
    /**
     * getter for offsety
     * @return int offsety
     */
    double GetYOffset() const { return mYOffset; }
    /**
     * getter for scale
     * @return scale
     */
    double GetScale() const { return mScale; }

    /**
     * getter for width
     * @return pixel width
     */
    double GetPixelWidth() const { return mPixelWidth; }

    /**
     * getter for pixel height
     * @return pixel height
     */
    double GetPixelHeight() const { return mPixelHeight; }

    void AddFront(std::shared_ptr<Item> item);
    void Eater(Item *eater);
    void HeadbuttContainer(Item *headbuttItem);
    void Accept(ItemVisitor *visitor);
    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    bool TakenSquare(int x, int y);
    void SetXray(std::shared_ptr<Xray> xray);
    void MoveDigit(int digit);
    void SetMessageBoardVisible(bool isVisible);
    bool IsMessageBoardVisible() const;
    void CheckSolution();
    void RevealSquare();
    std::vector<int> GetAllDigitsInGrid();
};

#endif //PROJECT1_SUDOKULIB_SUDOKU_H
