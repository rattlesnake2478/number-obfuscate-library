cmake_minimum_required(VERSION 3.9)
project(number_obfuscate)

# Set variables
include(${CMAKE_SOURCE_DIR}/cmake/SetEnv.cmake)

# Library sources
add_subdirectory(${LIBRARY_FOLDER})

# Library examples
add_subdirectory(examples)

# Install targets
include(${CMAKE_SOURCE_DIR}/cmake/InstallConfig.cmake)