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
/**
 * Visits Givens
 *
 */
class GivenVisitor : public ItemVisitor
{
private:

//    bool mGivenCheck = false;
    /// bool if the item is a given
    bool mIsGiven = false;
    /// given we are currently at
    Given* mThisGiven;
    /// given count
    int mGivenCounter = 0;

public:
//    GivenVisitor() : mGivenCheck(false) {}


    void VisitGiven(Given* given)
    {
        mThisGiven = given;
//        mGivenCheck = true;
        mIsGiven = true;
        mGivenCounter++;
    }

    /**
     * @return bool member variable
     */
    bool IsGiven() { return mIsGiven; }
    /**
     * @return value of given
     */
    int GetValue() { return mThisGiven->GetValue(); }

//    bool GivenChecker() const
//    {
//        return mGivenCheck;
//
//    }
    /**
     * @return given count
     */
    int GetGivenCounter() { return mGivenCounter; }

};

#endif //PROJECT1_SUDOKULIB_GIVENVISITOR_H
