project(SudokuLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h
        pch.h
        SudokuView.cpp
        SudokuView.h
        Sudoku.cpp
        Sudoku.h
        Item.cpp
        Item.h
        Digit.cpp
        Digit.h
        Given.cpp
        Given.h
        Sparty.cpp
        Sparty.h
        Scoreboard.cpp
        Scoreboard.h
        GridTile.cpp
        GridTile.h
        Xray.h
        Xray.cpp
        LevelLoad.cpp
        LevelLoad.h
        Container.cpp
        Container.h
        MessageBoard.cpp
        MessageBoard.h
        LevelVisitor.cpp
        LevelVisitor.h
        SolveLoad.cpp
        SolveLoad.h
        DigitVisitor.cpp
        DigitVisitor.h
)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})