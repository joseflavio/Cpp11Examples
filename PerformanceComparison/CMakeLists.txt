CMAKE_MINIMUM_REQUIRED(VERSION 2.8 FATAL_ERROR)

SET(ProjectName "PerfComparison")
SET(TargetCpp03 ${ProjectName}_03.out)
SET(TargetCpp11 ${ProjectName}_11.out)


PROJECT(${ProjectName})

# ADD_DEFINITIONS(-DSHOW_ERRORS)

INCLUDE_DIRECTORIES("src/include")

FILE(GLOB ProjectCppSources "src/src/*.cpp")
ADD_EXECUTABLE(${TargetCpp03} ${ProjectCppSources})
ADD_EXECUTABLE(${TargetCpp11} ${ProjectCppSources})


SET(EXECUTABLE_OUTPUT_PATH "build/")

# -fomit-frame-pointer = performance for small functions
# -fstack-protector-strong / --param=ssp-buffer-size=4 = security, not support by all compilers
LIST( APPEND CMAKE_CXX_FLAGS "-pipe -Wall -Wextra -Werror -O3" )

SET_TARGET_PROPERTIES(${TargetCpp11} PROPERTIES COMPILE_FLAGS "-std=c++11")

