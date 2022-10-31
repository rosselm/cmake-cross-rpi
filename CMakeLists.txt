cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_TOOLCHAIN_FILE $ENV{HOME}/rpi-toolchain.cmake)
project(cmake-cpp-arm-gnueabihf VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cmake-cpp-arm-gnueabihf main.cpp)
add_subdirectory(src)

# C version als builds correctly
# add_executable(cmake-cpp-arm-gnueabihf hello.c)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "hello")