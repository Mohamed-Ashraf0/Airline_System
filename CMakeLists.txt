cmake_minimum_required(VERSION 3.10)

# Project name
project(AirlineReservationProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(header)

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add executable
add_executable(AirlineReservationProject ${SOURCES})