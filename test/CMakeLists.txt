cmake_minimum_required(VERSION 3.15.0)

set(THIS Tests)

set(SOURCES 
    DataTests.cpp
)

add_executable(${THIS} ${SOURCES})
target_include_directories(${THIS} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src)
target_link_libraries(${THIS} PUBLIC
    gtest_main
    bbox_collision
)

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)