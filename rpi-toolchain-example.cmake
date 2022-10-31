set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_THREAD_LIBS_INIT -lpthread)

set(CMAKE_SYSROOT $ENV{HOME}/rpisysroot)

set(CMAKE_C_COMPILER /usr/local/opt/llvm/bin/clang)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
set(GCC_TOOLCHAIN /usr/local/opt/arm-linux-gnueabihf-binutils)

set(RPI_FLAGS
    "--target=arm-linux-gnueabihf \
    --gcc-toolchain=${GCC_TOOLCHAIN} \
    -isysroot ${CMAKE_SYSROOT} \
    --sysroot ${CMAKE_SYSROOT}")

set(CMAKE_C_FLAGS_INIT ${RPI_FLAGS})
set(CMAKE_CXX_FLAGS_INIT "${RPI_FLAGS} \
    -stdlib++-isystem ${CMAKE_SYSROOT}/usr/include/c++/10 \
    -isystem ${CMAKE_SYSROOT}/usr/include/arm-linux-gnueabihf/c++/10 \
    -std=c++20"
)

set(CMAKE_EXE_LINKER_FLAGS_INIT
    "${RPI_FLAGS} \
    -L${CMAKE_SYSROOT}/usr/lib/gcc/arm-linux-gnueabihf/10 \
    -B${CMAKE_SYSROOT}/usr/lib/gcc/arm-linux-gnueabihf/10"
)

# these variables tell CMake to avoid using any binary it finds in 
# the sysroot, while picking headers and libraries exclusively from it
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)