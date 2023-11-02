/**
 * @file TeamFeatureVisitor.h
 * @author Tess Murphy
 *
 * Declaration for level 3 team featire
 */

#ifndef PROJECT1_SUDOKULIB_TEAMFEATUREVISITOR_H
#define PROJECT1_SUDOKULIB_TEAMFEATUREVISITOR_H

#include "ItemVisitor.h"
#include "TeamFeature.h"

/**
 * Team feature visitor
 */
class TeamFeatureVisitor : public ItemVisitor
{
public:
    /**
    * Visit a TeamFeature object
    * @param teamFeature item we are visiting
    */
    void VisitTeamFeature(TeamFeature *teamFeature) override
    {
        mTeamFeature = teamFeature;
        mIsTeamFeature = true;

    }
    /**
    * Determine if item is a team feature
    * @return true is item is a team feature, false otherwise
    */
    bool IsTeamFeature() { return mIsTeamFeature; }

    /**
    * Determine if item is a team feature
    * @return team feature
    */
    TeamFeature* GetTeamFeature() {return mTeamFeature; }

    /**
    * Set target location of dr owen
    * @param x location of x
     * @param y location of y
    */
    void SetDrOwenTargetLocation(int x, int y)
    {
        mTeamFeature->SetTargetLocation(x, y);
    }

private:
    /// false if not team feature
    bool mIsTeamFeature = false;

    /// team feature
    TeamFeature* mTeamFeature;
};

#endif //PROJECT1_SUDOKULIB_TEAMFEATUREVISITOR_H
