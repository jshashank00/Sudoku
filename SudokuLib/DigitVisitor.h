/**
 * @file DigitVisitor.h
 * @author shash
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_DIGITVISITOR_H
#define PROJECT1_SUDOKULIB_DIGITVISITOR_H

//#include "Digit.h"

/**
 * Visits Digits
 */
///
class DigitVisitor
{
private:
    bool DigitCheck;
    bool mIsDigit = true;

public:
    DigitVisitor() : DigitCheck(false) {}

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
