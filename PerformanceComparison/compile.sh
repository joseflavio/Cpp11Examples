#/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

echo Compiling using Cpp03 and GCC 4.3.2
/opt/gcc-4.3.2/bin/g++ -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/pcomp_cpp03_gcc432.out
echo done.

# Missing -fsanitize=address -fsanitize=leak
export set COMP_FLAGS="-std=c++11 -Werror -Wall -Wextra"
export set MY_INCLUDES="-I./src/include/"

echo "Compiler flags: $COMP_FLAGS"

echo Compiling using Cpp11 and GCC 4.9.1
~seidelde/local/gcc/bin/g++ ${MY_INCLUDES} ${COMP_FLAGS} ./src/src/*.cpp -o ./build/pcomp_cpp11_gcc491.out
echo done.


echo Compiling using Cpp11 and Clang 3.5.0
~seidelde/local/clang/bin/clang++ -std=c++11 -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/pcomp_cpp11_clang350.out
echo done.

# Need for runtime? To be checked
# export LD_LIBRARY_PATH="~seidelde/local/gcc/4.9.1/lib64"

