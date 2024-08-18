cmake_minimum_required(VERSION 3.5.0)
project(craftsim VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES ${PROJECT_ROOT_DIR} src/*.cpp src/*.h)

add_executable(craftsim ${SRC_FILES})

