cmake_minimum_required(VERSION 3.10)

# Project name
project(AirlineReservationProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/header)
include_directories(${CMAKE_SOURCE_DIR}/header/external) # For nlohmann/json.hpp
include_directories(${CMAKE_SOURCE_DIR}/libs/bcrypt)     # For bcrypt

# Source files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE BCRYPT_SOURCES "${CMAKE_SOURCE_DIR}/libs/bcrypt/*.c")

# Add executable
add_executable(AirlineReservationProject ${SOURCES} ${BCRYPT_SOURCES})

# Define platform-specific macros
if (WIN32)
    target_compile_definitions(AirlineReservationProject PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Set the working directory to the source directory for runtime
set_target_properties(AirlineReservationProject PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

# Adjust compiler warning levels
if (MSVC)
    target_compile_options(AirlineReservationProject PRIVATE /W3 /wd4996 /wd4267 /wd4244)
else()
    target_compile_options(AirlineReservationProject PRIVATE -Wall -Wextra -Wno-shadow)
endif()