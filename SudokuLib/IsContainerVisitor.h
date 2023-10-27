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
    * Visit a Container object
    * @param container item we are visiting
    */
    void VisitContainer(Container *container) override
    {
        mContainer = container;
        mIsContainer = true;

    }
    /**
    * Determine if item is a container
    * @return true is item is a container, false otherwise
    */
    bool IsContainer() { return mIsContainer; }

    /**
    * Determine if item is a container
    * @return Container container
    */
    Container* GetContainer() {return mContainer; }

private:
    /// false if not container
    bool mIsContainer = false;

    /// container we headbutt
    Container* mContainer;
};


#endif //PROJECT1_SUDOKULIB_ISCONTAINERVISITOR_H
