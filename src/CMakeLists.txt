cmake_minimum_required(VERSION 3.15.0)

set(HEADERS 
    Data.h
)
set(SOURCES 
    Main.cpp 
    Data.cpp
)


add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

