cmake_minimum_required(VERSION 3.5)

project(App-Template-Selector VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(GTest REQUIRED)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/nlohmann_json)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

include_directories(${INCLUDE_DIR})
include_directories(${LIBRARY_DIR})
include_directories(${TEST_DIR})

# The rest of the project
set(PROJECT_SOURCES
    src/main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(App-Template-Selector
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/Controllers/WindowOrganiser.cpp src/Models/ProgLangScanner.cpp src/Models/ReaderWriterFactory.cpp src/Views/LangSelectWindow.cpp
        include/Controllers/WindowOrganiser.h include/Models/IJsonReaderWriter.h include/Models/ProgLangScanner.h include/Models/ReaderWriterFactory.h include/Views/LangSelectWindow.h
        libs/nlohmann_json/json.hpp libs/nlohmann_json/json_fwd.hpp
        include/Models/TemplateScanner.h src/Models/TemplateScanner.cpp
        include/Utils/macros.h
        test/tst_directoryexiststest.h
        include/Utils/pathvalidator.h src/Utils/pathvalidator.cpp
        include/Utils/errormacros.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET App-Template-Selector APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(App-Template-Selector SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(App-Template-Selector
            ${PROJECT_SOURCES}
        )
    endif()
endif()

add_compile_definitions(RUN_TESTS=false)
enable_testing()

target_link_libraries(App-Template-Selector PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${GTEST_LIBRARIES})
add_test(FileDirectoryExistenceTest App-Template-Selector)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.App-Template-Selector)
endif()
set_target_properties(App-Template-Selector PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS App-Template-Selector
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(App-Template-Selector)
endif()
