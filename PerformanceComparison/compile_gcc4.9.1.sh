#/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

~seidelde/local/gcc/bin/g++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o build/Cpp11Examples_gcc491.out

# Need for runtime
export LD_LIBRARY_PATH="~seidelde/local/gcc/4.9.1/lib64"
