/**
 * @file TeamFeature.cpp
 * @author Shashank Jayaram
 */
#include "pch.h"
#include "TeamFeature.h"
#include <wx/graphics.h>
using namespace std;

/// Character speed in pixels per second
const double MaxSpeed = 500.00;

/**
 * Constructor for team feature
 * @param sudoku game we are in
 * @param filename image filename
 */
TeamFeature::TeamFeature(Sudoku *sudoku, const wxString &filename) : Item(sudoku, filename)
{
}

/**
 * Set dr owen location
 * @param x dr owen new location
 * @param y owen new location
 */
void TeamFeature::SetTargetLocation(int x, int y)
{
    mTargetX = x;
    mTargetY = y;
    mIsMoving = true;
}

/**
 * Update dr owen animations
 * @param elapsed time for animations
 */
void TeamFeature::Update(double elapsed)
{
    if (mIsMoving)
    {
        double dx = mTargetX - GetX();
        double dy = mTargetY - GetY();

        double distance = sqrt(dx * dx + dy * dy);

        if (distance < MaxSpeed * elapsed)
        {
            SetLocation(mTargetX, mTargetY);
            mIsMoving = false;
        }
        else
        {
            double moveX = dx / distance * MaxSpeed * elapsed;
            double moveY = dy / distance * MaxSpeed * elapsed;
            SetLocation(GetX() + moveX, GetY() + moveY);
        }
    }
}