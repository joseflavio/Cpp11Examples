#/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

export OUTPUT_BASE_NAME="rot13"

echo Compiling using Cpp11 and GCC 4.9.1
~seidelde/local/gcc/bin/g++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/${OUTPUT_BASE_NAME}_cpp11_gcc491.out
echo done.


echo Compiling using Cpp11 and Clang 3.5.0
~seidelde/local/clang/bin/clang++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/${OUTPUT_BASE_NAME}_cpp11_clang350.out
echo done.

# Need for runtime? To be checked
# export LD_LIBRARY_PATH="~seidelde/local/gcc/4.9.1/lib64"

