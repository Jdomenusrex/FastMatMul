#!/bin/bash

set -e

mkdir -p build
cd build

cmake -DCMAKE_BUILD_TYPE=Release ..

cmake --build . -j$(nproc)

ctest --output-on-failure