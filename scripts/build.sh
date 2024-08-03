#!/bin/bash

# project directory
PROJ_DIR="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/../"

BUILD_DIR=$PROJ_DIR/build/
cmake -S $PROJ_DIR -B $BUILD_DIR
cmake --build $BUILD_DIR -j