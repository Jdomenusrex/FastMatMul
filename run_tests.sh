#!/bin/bash

set -e  

rm -rf build
mkdir build && cd build

cmake ..
cmake --build .

./tests/test_matmul