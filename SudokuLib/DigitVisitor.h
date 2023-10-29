/**
 * @file DigitVisitor.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_DIGITVISITOR_H
#define PROJECT1_SUDOKULIB_DIGITVISITOR_H

#include "ItemVisitor.h"
#include "Digit.h"


/**
 * Visits Digits
 *
 */
///
class DigitVisitor : public ItemVisitor
{
private:
    bool DigitCheck = false;

    /// bool if the item is a digit
    bool mIsDigit = false;

    Digit* mThisDigit;

public:
    DigitVisitor() : DigitCheck(false) {}


    void VisitDigit(Digit* digit) override
    {
        mThisDigit = digit;
        DigitCheck = true;
        mIsDigit = true;
    }

    /**
     * @return bool member variable
     */
    bool IsDigit() { return mIsDigit; }

    int GetValue() { return mThisDigit->GetValue(); }



//    void VisitDigit(Digit* digit) override
//    {
//        DigitCheck = true;
//    }

    // Add other Visit functions for other item types if needed

    bool DigitChecker() const
    {
        return DigitCheck;

    }
};
#endif //PROJECT1_SUDOKULIB_DIGITVISITOR_H
