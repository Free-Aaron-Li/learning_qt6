cmake_minimum_required(VERSION 3.16)

project(samp4_1_layout_visualization VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

get_filename_component(SECONDARY_DIR "${PROJECT_SOURCE_DIR}/.." ABSOLUTE)
get_filename_component(SECONDARY_DIR_NAME "${SECONDARY_DIR}" NAME)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/${SECONDARY_DIR_NAME})

set(PROJECT_SOURCES
        src/main.cpp
        ui/mainwindow.cpp
        ui/mainwindow.h
        ui/mainwindow.ui
        test/qstring_and_qchar.cpp
        include/test.hpp
)


if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(samp4_1_layout_visualization
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET samp4_1_layout_visualization APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else ()
    if (ANDROID)
        add_library(samp4_1_layout_visualization SHARED
                ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else ()
        add_executable(samp4_1_layout_visualization
                ${PROJECT_SOURCES}
        )
    endif ()
endif ()

target_link_libraries(samp4_1_layout_visualization PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if (${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.samp4_1_layout_visualization)
endif ()
set_target_properties(samp4_1_layout_visualization PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS samp4_1_layout_visualization
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(samp4_1_layout_visualization)
endif ()
