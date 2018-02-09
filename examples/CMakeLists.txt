include_directories(${CMAKE_SOURCE_DIR}/number_obfuscate)
add_executable(example main.cpp)

target_link_libraries(example ${LIBRARY_NAME})