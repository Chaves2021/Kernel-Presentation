#!/bin/bash -e
cd src
make
cd ..
cp src/*.ko fs/
