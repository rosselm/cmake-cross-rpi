cmake_minimum_required(VERSION 3.20.0)
set(CMAKE_TOOLCHAIN_FILE $ENV{HOME}/rpi-toolchain.cmake)
project(cmake-cpp-arm-gnueabihf VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cmake-cpp-arm-gnueabihf main.cpp gsl_tests.cpp gsl_tests.h)

# --> THIS if for my own gpio (the one from derek molloy)
# add_subdirectory(src)
# target_link_libraries (cmake-cpp-arm-gnueabihf LINK_PUBLIC gpio)

# to get rid of the error: undefined reference to `pthread_create'
# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# target_link_libraries(cmake-cpp-arm-gnueabihf PRIVATE Threads::Threads)
# <--

# for pigpio - which is delivered with the OS
# Find the pigpio libraries.
find_library(pigpio_LIBRARY NAMES libpigpio.so)
find_library(pigpiod_if_LIBRARY NAMES libpigpiod_if.so)
find_library(pigpiod_if2_LIBRARY NAMES libpigpiod_if2.so)
target_link_libraries(cmake-cpp-arm-gnueabihf PRIVATE "${pigpio_LIBRARY}")
# for pthreads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(cmake-cpp-arm-gnueabihf PRIVATE Threads::Threads)
#####

### for the GSL : (C++) Guidelines Support Library
include(FetchContent)

FetchContent_Declare(GSL
    GIT_REPOSITORY "https://github.com/microsoft/GSL"
    GIT_TAG "v4.0.0"
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(GSL)

target_link_libraries(cmake-cpp-arm-gnueabihf PRIVATE Microsoft.GSL::GSL)
### end GSL

# C version als builds correctly
# add_executable(cmake-cpp-arm-gnueabihf hello.c)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "hello")