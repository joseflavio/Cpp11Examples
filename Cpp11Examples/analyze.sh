#/bin/bash
clang++ -std=c++11 --analyze -Xanalyzer -analyzer-output=text -I./src/include ./src/src/Main.cpp

