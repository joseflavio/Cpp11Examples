#/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

export LD_LIBRARY_PATH="~seidelde/local/gcc/4.9.1/lib64"
~seidelde/local/clang/bin/clang++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o build/Cpp11Examples_clang350.out

