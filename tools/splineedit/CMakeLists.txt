cmake_minimum_required(VERSION 3.8)
project(SplineEdit)

find_package(Qt5 COMPONENTS Core Gui Widgets)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

set(SPLINEEDIT_SRC
    SplineEdit.qrc
    SplineEdit.ui
    
    SplineEdit.cpp
    FontModel.cpp
    
    Font.cpp
    Glyph.cpp
)

add_executable(SplineEdit ${SPLINEEDIT_SRC})
target_link_libraries(SplineEdit Qt5::Gui Qt5::Core Qt5::Widgets)

if(WIN32)
    get_filename_component(_qt_bin_dir "${QT_QMAKE_EXECUTABLE}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE NAMES windeployqt.exe HINTS "${_qt_bin_dir}")
    message("Found windeployqt executable: ${WINDEPLOYQT_EXECUTABLE}")
    message("Binary is in: $<TARGET_FILE_DIR:SplineEdit>")
    add_custom_command(TARGET SplineEdit COMMAND ${WINDEPLOYQT_EXECUTABLE} "$<TARGET_FILE:SplineEdit>")
endif()
