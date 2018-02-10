include_directories(${CMAKE_SOURCE_DIR}/${LIBRARY_FOLDER})
add_executable(example main.cpp)

target_link_libraries(example ${LIBRARY_NAME})