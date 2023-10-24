/**
 * @file SolveLoad.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include "SolveLoad.h"

SolveLoad::SolveLoad(const wxString &filename, Sudoku * sudoku): mSudoku(sudoku)
{
    wxXmlDocument xmlDoc;
    if (!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Sudoku file");
        return;
    }

    auto root = xmlDoc.GetRoot();
    for (auto node = root->GetChildren(); node; node = node->GetNext())
    {
        if (node->GetName() == L"game")
        {
            XmlGame(node);
        }
    }
}

/**
 * Handle a node of type game.
 * @param node XML node
 */
void SolveLoad::XmlGame(wxXmlNode *node)
{
    mCol = node->GetAttribute(L"col");
    mRow = node->GetAttribute(L"row");
    mSolution = node->GetNodeContent();
}