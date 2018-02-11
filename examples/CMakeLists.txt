include_directories(${CMAKE_SOURCE_DIR}/${LIBRARY_FOLDER})
add_executable(example main.cpp)
add_executable(runTest test.cpp)

target_link_libraries(example ${LIBRARY_NAME})
target_link_libraries(runTest ${LIBRARY_NAME} matheval)