cmake_minimum_required(VERSION 3.5)

project(TimoStockTool VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)

else()
    find_package(Qt6 COMPONENTS Core5Compat REQUIRED)
endif()

find_package(Qt6 COMPONENTS Sql REQUIRED)
find_package(cpprestsdk CONFIG REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

add_subdirectory(QHotkey)
add_subdirectory(data)

set(TS_FILES TimoStockTool_zh_CN.ts)

file(GLOB QRC_SOURCE_FILES *.qrc)
file(GLOB SRC *.cpp *.h framelesswidget/*.h framelesswidget/*.cpp ui/*.h ui/*.cpp *.ui db/*.h db/*.cpp)
file(GLOB UI_SRC *.ui  ui/*.ui)
set(PROJECT_SOURCES
        ${UI_SRC}
        ${SRC}
        ${QRC_SOURCE_FILES}
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TimoStockTool
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TimoStockTool APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(TimoStockTool SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TimoStockTool
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

if (WIN32)
target_link_libraries(TimoStockTool PRIVATE Qt${QT_VERSION_MAJOR}::Widgets datasource qhotkey Qt6::Sql)
else()
target_link_libraries(TimoStockTool PRIVATE Qt${QT_VERSION_MAJOR}::Widgets datasource qhotkey Qt6::Core5Compat Qt6::Sql)
endif()

set_target_properties(TimoStockTool PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TimoStockTool)
endif()
