cmake_minimum_required(VERSION 3.15.0)

project(bbox_collision C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

add_subdirectory(src)

add_subdirectory(test)


#add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
#message("${CMAKE_PROJECT_NAME} = ${CMAKE_PROJECT_NAME}")

