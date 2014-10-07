#/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

/opt/gcc-4.3.2/bin/g++ -Werror -Wall -Wextra -I./src/include ./src/src/*.cpp -o ./build/Cpp11Examples_cpp03_gcc432.out

# Need for runtime
# export LD_LIBRARY_PATH="~seidelde/local/gcc/4.9.1/lib64"
