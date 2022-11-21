# C++ Working Suite

1. [Introduction](#introduction)
2. [Installation](#installation)
3. [Content](#content)
4. [ToDo](#todo)
5. [Links](#links)

---
<a name="introduction"></a>

## Introduction

I created this repository as a playground to better my overall skills as a software developer. Instead of writing some code, building it and leaving it as in a state that can be best summarized as "proof of concept", I try to add some additional concepts a recently learnt:

- buildable runnables on several operating systems
- describing the build steps with CMakeLists.txt
- structuring the project in several components that lie in different folders
- verifying the intended behavior with unittests

I hope this repository can be used as a template for future c++ projects.

---
<a name="installation"></a>

## Installation

Clone Googletest in this folder and use CMake to build the project:
`git clone git@github.com:google/googletest.git`
`mkdir build`
`cd build`
`cmake ..`
`cmake --build .`

Under Windows, the runnable is located as `build/Debug/Tests.exe`. On a linux machine, the runnable is in the build folder. The runnable just runs a couple of tests that should all pass.

---
<a name="content"></a>

## Content

Currently all four or so files are in the project root folder.

### Functional

The code used in this project is no dummy code that serves no purpose. Currently it is planned to implement some basic geometric objects (points, lines, boxes, triangles) and add some intersection functionality. This library can then be used in a minimal physical simulation to let an Ackermann vehicle behave in 2D space.


---
<a name="todo"></a>

## ToDo

- using several libraries and linking them against each other
- auto build (github actions)
- auto test (github actions)
- building on several OS
- clone dir... (googletest)
- download and store other artifacts


---
<a name="links"></a>

## Links

Here are a couple of links I found useful while working on this project:
mathematical background
https://usmanr149.github.io/urmlblog/geometry/2022/10/14/Point-in-Rectangle.html
other possibility
https://martin-thoma.com/how-to-check-if-a-point-is-inside-a-rectangle/
yet another possibility
baricentric coordinates


introduction to cmake and googletest
https://www.youtube.com/watch?v=Lp1ifh9TuFI
