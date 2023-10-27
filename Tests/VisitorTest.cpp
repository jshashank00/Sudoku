/**
 * @file VisitorTest.cpp
 * @author Lillian Yanke
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Sudoku.h>
#include <Given.h>
#include <Digit.h>
#include <Sparty.h>
#include <Container.h>
#include <Xray.h>
#include "LevelLoad.h"
#include "DigitVisitor.h"

class VisitorTest : public ItemVisitor
{
public:

    virtual void VisitGiven(Given* given) override  { mNumGivens++; }

    int mNumGivens = 0;

    virtual void VisitDigit(Digit* digit) override  { mNumDigits++; }

    int mNumDigits = 0;

    virtual void VisitSparty(Sparty* sparty) override  { mNumSparty++; }

    int mNumSparty = 0;

    virtual void VisitContainer(Container* sparty) override  { mNumContainer++; }

    int mNumContainer = 0;

    virtual void VisitXray(Xray* xray) override  { mNumXray++; }

    int mNumXray = 0;
};


TEST(VisitorTest, Visitor)
{
    Sudoku sudoku;
    LevelLoad level("levels/level1.xml", &sudoku);

    /**
    VisitorTest visitor;
    sudoku.Accept(&visitor);
    std::cout<<visitor.mNumGivens;
    ASSERT_EQ(28, visitor.mNumGivens) <<
                                        L"Visitor number";
    std::cout<<visitor.mNumDigits;
    ASSERT_EQ(53, visitor.mNumDigits) <<
                                      L"Visitor number";
    std::cout<<visitor.mNumSparty;
    ASSERT_EQ(1, visitor.mNumSparty) <<
                                      L"Visitor number";

    std::cout<<visitor.mNumContainer;
    ASSERT_EQ(0, visitor.mNumContainer) <<
                                      L"Visitor number";

    std::cout<<visitor.mNumXray;
    ASSERT_EQ(1, visitor.mNumXray) <<
                                      L"Visitor number";
    */

    for (auto item : sudoku.GetItems())
    {
        DigitVisitor visitor1;
        item->Accept(&visitor1);
        std::cout<<visitor1.IsDigit()<<std::endl;

    }


}