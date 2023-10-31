/**
 * @file TeamFeature.h
 * @author Shashank Jayaram
 *
 *
 */

#ifndef PROJECT1_SUDOKULIB_TEAMFEATURE_H
#define PROJECT1_SUDOKULIB_TEAMFEATURE_H
/**
 * Class for TeamFeature
 */
#include "Item.h"
//class Sudoku;
class TeamFeature : public Item
{
private:

public:
    TeamFeature(Sudoku *sudoku, const wxString &filename);

    TeamFeature() = delete;

    /// Copy constructor (disabled)
    TeamFeature(const TeamFeature &) = delete;

    /// Assignment operator
    void operator=(const TeamFeature &) = delete;

//    void XmlLoadBack(wxXmlNode *itemNode, wxXmlNode *decNode, double height);
};

#endif //PROJECT1_SUDOKULIB_TEAMFEATURE_H
