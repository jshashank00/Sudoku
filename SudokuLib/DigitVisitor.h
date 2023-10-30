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

    /// bool if the item is a digit
    bool mIsDigit = false;

    Digit* mThisDigit;

    int mDigitCounter = 0;

public:
void VisitDigit(Digit* digit) override
    {
        mThisDigit = digit;
        mIsDigit = true;
        mDigitCounter++;
    }

    /**
     * @return bool member variable
     */
    bool IsDigit() { return mIsDigit; }

    int GetValue() { return mThisDigit->GetValue(); }

    int GetDigitCount() { return mDigitCounter; }

};
#endif //PROJECT1_SUDOKULIB_DIGITVISITOR_H
