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
class DigitVisitor : public ItemVisitor
{
private:

    /// bool if the item is a digit
    bool mIsDigit = false;

    /// digit we are currently at
    Digit* mThisDigit;

    /// digit count
    int mDigitCounter = 0;

public:
    /**
     * Digit visitor
     * @param digit Digit pointer
     */
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
    /**
     * @return digit value
     */
    int GetValue() { return mThisDigit->GetValue(); }
    /**
     * @return the current digit
     */
    Digit* GetDigit() {return mThisDigit;}
    /**
     * @return number of digits
     */
    int GetDigitCount() { return mDigitCounter; }

};
#endif //PROJECT1_SUDOKULIB_DIGITVISITOR_H
