#!/bin/bash
set -e

BLUE='\033[34m'
GREEN='\033[32m'
RESET='\033[0m'
HEADER='\033[1;44m'

mkdir -p build
cd build

cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -j$(nproc)

./FastMatMul > raw_results.txt

echo
echo -e "${HEADER} Matrix Multiplication Benchmark Results ${RESET}"
echo

sed -n '/---BEGIN_CSV---/,/---END_CSV---/p' raw_results.txt | \
    grep -v "BEGIN\|END" | \
    column -t -s','

echo
echo -e "${GREEN}Benchmark completed!${RESET}"