#/bash/sh
valgrind --tool=callgrind ./build/pcomp_cpp03_gcc432.out
valgrind --tool=callgrind ./build/pcomp_cpp11_clang350.out

