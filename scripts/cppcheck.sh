#!/bin/bash

# get repo base directory
# https://stackoverflow.com/a/4774063
PROJ_DIR="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/../"

# deps dirs
EIGEN_INCL=$PROJ_DIR/build/_deps/eigen3-src/
SPDLOG_INCL=$PROJ_DIR/build/_deps/spdlog-src/include/
SPDLOG_SRC=$PROJ_DIR/build/_deps/spdlog-src/src/

# get files to analyze
FILES="`find $PROJ_DIR/src/ -type f \( -name "*.cpp" \) ! -name "*_test.cpp"`"

# run analysys on files
# make cppcheck build dir
CPPCHECK_BUILD_DIR=$PROJ_DIR/.cppcheck-cache/
mkdir -p $CPPCHECK_BUILD_DIR/

# run cppcheck
cppcheck $FILES \
    --cppcheck-build-dir=$CPPCHECK_BUILD_DIR \
    --inline-suppr \
    --suppress='noExplicitConstructor' \
    --enable=style \
    --std=c++20 \
    --platform=unix64 \
    --error-exitcode=1 \
    -I $PROJ_DIR/src/ \
    -i $PROJ_DIR/build/ \
    -i $PROJ_DIR/tests/

