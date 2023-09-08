#!/bin/bash

mkdir build

cp board.txt build/board.txt

cd build

cmake ..
make

