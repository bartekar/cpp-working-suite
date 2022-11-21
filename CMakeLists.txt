cmake_minimum_required(VERSION 3.10.0)

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

add_subdirectory(test)

#add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
#target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)
#message("${CMAKE_PROJECT_NAME} = ${CMAKE_PROJECT_NAME}")

