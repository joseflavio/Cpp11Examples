#/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

echo Compiling using Cpp11 and GCC 4.9.1
~seidelde/local/gcc/bin/g++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/cpp11examples_cpp11_gcc491.out
echo done.


echo Compiling using Cpp11 and Clang 3.5.0
~seidelde/local/clang/bin/clang++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/cpp11examples_cpp11_clang350.out
echo done.

# Need for runtime? To be checked
echo 'export LD_LIBRARY_PATH="/remote/intdeliv/seidelde/local/gcc/4.9.1/lib64:${LD_LIBRARY_PATH}"'

