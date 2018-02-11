set (TESTS_SOURCES
        mainTest.cpp)
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/${LIBRARY_FOLDER})
set (TEST test_${PROJECT_NAME})
add_executable (${TEST} ${TESTS_SOURCES})
target_link_libraries (${TEST} ${PROJECT} ${Boost_LIBRARIES} ${LIBRARY_NAME} matheval)
add_test (${TEST} ${CMAKE_BINARY_DIR}/bin/${TEST})
