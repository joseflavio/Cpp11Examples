CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

SET(ProjectName "Cpp11Examples")

PROJECT(${ProjectName})

# ADD_DEFINITIONS(-DSHOW_ERRORS)

INCLUDE_DIRECTORIES("src/include")

FILE(GLOB ProjectCppSources "src/src/*.cpp")
ADD_EXECUTABLE(${ProjectName}.out ${ProjectCppSources})

SET(EXECUTABLE_OUTPUT_PATH "build/")

# -fomit-frame-pointer = performance for small functions
# -fstack-protector-strong / --param=ssp-buffer-size=4 = security, not support by all compilers

LIST( APPEND CMAKE_CXX_FLAGS "-std=c++11 -pipe -Wall -Wextra -Werror -O3 -fstack-protector" )
