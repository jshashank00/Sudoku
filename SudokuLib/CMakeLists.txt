project(SudokuLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h
        pch.h
        SudokuView.cpp
        SudokuView.h
        Sudoku.cpp
        Sudoku.h
        Item.cpp
        Item.h
        Number.cpp
        Number.h
        Digit.cpp
        Digit.h
        Given.cpp
        Given.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})