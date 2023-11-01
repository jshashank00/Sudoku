/**
 * @file TeamFeature.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_TEAMFEATURE_H
#define PROJECT1_SUDOKULIB_TEAMFEATURE_H
/**
 * Class for TeamFeature
 */
#include "Item.h"

class TeamFeature : public Item
{
private:

    double mTargetX = 0.0; ///< x where dr owen needs to move
    double mTargetY = 0.0; ///< y where dr owen needs to move
    bool mIsMoving = false; ///< track if dr owen is moving

public:
    TeamFeature(Sudoku *sudoku, const wxString &filename);

    /// destructor
    TeamFeature() = delete;

    /// Copy constructor (disabled)
    TeamFeature(const TeamFeature &) = delete;

    /// Assignment operator
    void operator=(const TeamFeature &) = delete;

    void SetTargetLocation(int x, int y) override;

    void Update(double deltaTime) override;

    /**
    * Accept a visitor
    * @param visitor The visitor we accept
    */
    void Accept(ItemVisitor* visitor) override { visitor->VisitTeamFeature(this); }


};

#endif //PROJECT1_SUDOKULIB_TEAMFEATURE_H
