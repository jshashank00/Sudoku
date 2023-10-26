/**
 * @file DigitVisitor.h
 * @author shash
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_DIGITVISITOR_H
#define PROJECT1_SUDOKULIB_DIGITVISITOR_H

#include "ItemVisitor.h"

/**
 * Visits Digits
 */
///
class DigitVisitor:public ItemVisitor
{
private:
bool DigitCheck;

public:
    DigitVisitor() : DigitCheck(false) {}

    void VisitDigit(Digit* digit) override
    {
        DigitCheck = true;
    }

    // Add other Visit functions for other item types if needed

    bool DigitChecker() const
    {
        return DigitCheck;

    }
};

#endif //PROJECT1_SUDOKULIB_DIGITVISITOR_H
