#!/bin/bash

set -e  

rm -rf build
mkdir -p build && cd build

cmake ..
cmake --build . -j$(nproc)

ctest --output-on-failure