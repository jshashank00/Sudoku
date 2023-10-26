/**
 * @file SolveLoad.cpp
 * @author Ishita Saripalle
 */

#include "pch.h"
#include <wx/dcbuffer.h>
#include "SolveLoad.h"

SolveLoad::SolveLoad(const wxString &filename, Sudoku * sudoku) :mSudoku(sudoku)
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
    mCol = node->GetAttribute(L"col"); // Convert column attribute to integer
    mRow = node->GetAttribute(L"row"); // Convert row attribute to integer
    wxString solution = node->GetNodeContent();

    // Calculate the starting X and Y positions based on mCol and mRow
    int x = wxAtoi(mCol) * 48;
    int y = wxAtoi(mRow) * 48;

    for (size_t i = 0; i < solution.length(); i++) {
        wxString digit = solution.Mid(i, 1);

        if (digit.IsNumber()) {
            x += 48;

            if (x >= (wxAtoi(mCol) + 9) * 48) {
                x = wxAtoi(mCol) * 48;
                y += 48;
            }
        }
    }
}










