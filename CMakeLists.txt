CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

PROJECT("Cpp11Example")

# ADD_DEFINITIONS(-DSHOW_ERRORS)

INCLUDE_DIRECTORIES(Cpp11Examples/include)

FILE(GLOB MyCSources Cpp11Examples/src/*.cpp)
ADD_EXECUTABLE(Cpp11ExamplesMain.out ${MyCSources})

SET(EXECUTABLE_OUTPUT_PATH build/)

# -fomit-frame-pointer = performance for small functions
# -fstack-protector-strong / --param=ssp-buffer-size=4 = security, not support by all compilers

LIST( APPEND CMAKE_CXX_FLAGS "-std=c++11 -pipe -Wall -Wextra -Werror -O3 -fstack-protector" )
