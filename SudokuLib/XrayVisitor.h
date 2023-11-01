/**
 * @file XrayVisitor.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_XRAYVISITOR_H
#define PROJECT1_SUDOKULIB_XRAYVISITOR_H

#include "ItemVisitor.h"
#include "Item.h"
#include "Xray.h"


/**
 * Xray visitor
 */
//class XrayVisitor: public ItemVisitor
//{
//public:
//    /**
//    * Visit a Xray object
//    * @param xray Xray we are visiting
//    */
//    void VisitXray(Xray *xray) override
//    {
//        mXray = xray;
//        mIsXray = true;
//
//    }
//    /**
//    * Determine if tile is landable
//    * @return true is tile is landable, false otherwise
//    */
//    bool IsContainer() { return mIsXray; }
//
//    /**
//    * Determine if tile is landable
//    * @return TileLandable tile
//    */
//    //Container* GetContainer() {return mX5
//    std::vector<std::shared_ptr<Item>>& GetItems() { return mXray->GetItems(); }
//
//
//
//private:
//    /// false if not container
//    bool mIsXray = false;
//
//    /// container we headbutt
//    Xray* mXray;
//};
#endif //PROJECT1_SUDOKULIB_XRAYVISITOR_H
