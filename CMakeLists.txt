CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

PROJECT("Cpp11Example")

INCLUDE_DIRECTORIES(Cpp11Examples/include)

FILE(GLOB MyCSources Cpp11Examples/src/*.cpp)
ADD_EXECUTABLE(Cpp11ExamplesMain.out ${MyCSources})

SET(EXECUTABLE_OUTPUT_PATH build/)

LIST( APPEND CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Werror -O3")
