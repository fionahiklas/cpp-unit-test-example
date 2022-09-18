cmake_minimum_required(VERSION 3.10)

project(UnitTestExample VERSION 0.0.1)

# Dependencies
find_package(Boost COMPONENTS filesystem system REQUIRED)

# Finding the source files
# TODO: See if there is a better way to do this
file(GLOB_RECURSE INC_FILES src/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Include the CMakeLists.txt from the tests subdirectory
add_subdirectory(test)

# Assign the include directories
include_directories(${Boost_INCLUDE_DIRS})

# Simple application 
set(SOURCE_FILES ${INC_FILES} ${SRC_FILES})
add_executable(appmain ${SOURCE_FILES})

