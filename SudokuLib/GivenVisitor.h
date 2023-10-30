/**
 * @file GivenVisitor.h
 * @author Ishita Saripalle
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_GIVENVISITOR_H
#define PROJECT1_SUDOKULIB_GIVENVISITOR_H

#include "ItemVisitor.h"
#include "Given.h"

class GivenVisitor : public ItemVisitor
{
private:
    bool GivenCheck = false;

    /// bool if the item is a digit
    bool mIsGiven = false;

    Given* mThisGiven;

    int mGivenCounter = 0;

public:
    GivenVisitor() : GivenCheck(false) {}


    void VisitGiven(Given* given)
    {
        mThisGiven = given;
        GivenCheck = true;
        mIsGiven = true;
        mGivenCounter++;
    }

    /**
     * @return bool member variable
     */
    bool IsGiven() { return mIsGiven; }

    int GetValue() { return mThisGiven->GetValue(); }

    bool GivenChecker() const
    {
        return GivenCheck;

    }

    int GetGivenCounter() { return mGivenCounter; }

};

#endif //PROJECT1_SUDOKULIB_GIVENVISITOR_H
