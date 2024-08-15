#!/bin/bash

cd tests
(mkdir build && cd build && conan install .. --build=gtest -s compiler.libcxx=libstdc++11 && cmake .. && cmake --build . -j 4 && ./bin/unit-tests) || (cd build && cmake --build . -j 4 && ./bin/unit-tests)
