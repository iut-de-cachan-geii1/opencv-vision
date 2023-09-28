# Copyright (c) 2019 Antoine Tran Tan
cmake_minimum_required(VERSION 3.5)
cmake_policy(SET CMP0074 NEW)

project(MyQtProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use clang-tidy if available 
find_program(CLANG_TIDY "clang-tidy")

if(CLANG_TIDY)
    message(STATUS "Found clang-tidy")
    set(CMAKE_CXX_CLANG_TIDY 
        clang-tidy 
        -warnings-as-errors=* 
        -checks=-*,readability-*,-readability-magic-numbers,-readability-isolate-declaration
    )
    set(CMAKE_C_CLANG_TIDY 
        clang-tidy 
        -warnings-as-errors=* 
        -checks=-*,readability-*,-readability-magic-numbers,-readability-isolate-declaration
    )
endif()

# Search for Boost static libraries only
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost 1.65.0 COMPONENTS unit_test_framework QUIET)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif()

# if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#     # Create an option to control whether to run the pre-configuration step
#     option(RUN_PRECONFIGURE "Run pre-configure step" ON)

#     # Only run the pre-configure step if the option is enabled
#     if(RUN_PRECONFIGURE)
#     # Run the pre-configure script
#     execute_process(
#         COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/configure.exe
#         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#     # Set the option to OFF so that the pre-configure step is not run again
#     set(RUN_PRECONFIGURE OFF CACHE INTERNAL "Pre-configure step has been run" FORCE)
#     endif()
# endif()

find_package(QT PATHS NAMES Qt6 Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets SerialPort REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Widgets Multimedia MultimediaWidgets SerialPort REQUIRED)
find_package(OpenCV REQUIRED) # http://opencv.org

include_directories(include)
file(GLOB_RECURSE header_files "include/*.h")

# Recurse into the "src" subdirectory. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.
add_subdirectory (src)
