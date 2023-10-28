/**
 * @file XrayFinder.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_XRAYFINDER_H
#define PROJECT1_SUDOKULIB_XRAYFINDER_H

#include "ItemVisitor.h"

class XrayFinder : public ItemVisitor
{
private:
    /// xray pointer
    Xray* mXray;

public:

    /**
     * Getter for xray
     * @return Xray* item
     */
    Xray* GetXray() const {return mXray;}

    /**
     * Visit an Xray object
     * @param xray xray we are visiting
     */
    void VisitXray(Xray* xray) override
    {
        mXray = xray;
    }

};

#endif //PROJECT1_SUDOKULIB_XRAYFINDER_H
