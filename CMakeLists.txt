cmake_minimum_required(VERSION 3.15.0)

project(bbox_collision C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

set(HEADERS 
    Data.h
)
set(SOURCES 
    Main.cpp 
    Data.cpp
)

add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

#add_subdirectory(test)
set(THIS Tests)
set(SOURCES
    DataTests.cpp
)

add_executable(${THIS} ${SOURCES})
target_link_libraries(${THIS} PUBLIC
    gtest_main
    bbox_collision
)

add_test(
    NAME ${THIS}
    COMMAND ${THIS}
)

#add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)
#message("${CMAKE_PROJECT_NAME} = ${CMAKE_PROJECT_NAME}")

