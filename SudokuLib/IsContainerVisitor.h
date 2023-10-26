/**
 * @file IsContainer.h
 * @author Tess Murphy
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_ISCONTAINERVISITOR_H
#define PROJECT1_SUDOKULIB_ISCONTAINERVISITOR_H

#include "ItemVisitor.h"

/**
 * Container visitor
 */
class IsContainerVisitor: public ItemVisitor
{
public:
    /**
    * Visit a TileLandable object
    * @param land tile we are visiting
    */
    void VisitContainer(Container *container) override
    {
        mContainer = container;
        mIsContainer = true;

    }
    /**
    * Determine if tile is landable
    * @return true is tile is landable, false otherwise
    */
    bool IsContainer() { return mIsContainer; }

    /**
    * Determine if tile is landable
    * @return TileLandable tile
    */
    Container* GetContainer() {return mContainer; }

private:
    /// false if not container
    bool mIsContainer = false;

    /// container we headbutt
    Container* mContainer;
};


#endif //PROJECT1_SUDOKULIB_ISCONTAINERVISITOR_H
