/**
 * @file ItemVisitor.h
 * @author Lillian Yanke
 *
 * Item visitor base class
 */

#ifndef PROJECT1_SUDOKULIB_ITEMVISITOR_H
#define PROJECT1_SUDOKULIB_ITEMVISITOR_H

class Given;
class Digit;
class Sparty;
class Container;
class Xray;

/**
 * Item visitor base class
 */
class ItemVisitor
{
protected:
    /**
      * Constructor
      */
      ItemVisitor() {}
public:
    virtual ~ItemVisitor() {}

    /**
     * Visit Given
     * @param given Given we are visiting
     */
     virtual void VisitGiven(Given* given) {}

    /**
   * Visit Digit
   * @param digit Given we are visiting
   */
    virtual void VisitDigit(Digit* digit) {}

    /**
     * Visit Sparty
     * @param sparty Given we are visiting
     */
    virtual void VisitSparty(Sparty* sparty) {}

    /**
     * Visit Container
     * @param container we are visiting
     */
    virtual void VisitContainer(Container* container) {}

    /**
     * Visit Xray
     * @param xray Xray we are visiting
     */
    virtual void VisitXray(Xray* xray) {}

 };

#endif //PROJECT1_SUDOKULIB_ITEMVISITOR_H
