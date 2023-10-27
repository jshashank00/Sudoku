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
 */
///
class DigitVisitor : public ItemVisitor
{
private:
    bool DigitCheck;

    /// bool if the item is a digit
    bool mIsDigit = false;

public:
    DigitVisitor() : DigitCheck(false) {}


    void VisitDigit(Digit* digit)
    {
        DigitCheck = true;
        mIsDigit = true;
    }

    /**
     * @return bool member variable
     */
    bool IsDigit() { return mIsDigit; }



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
