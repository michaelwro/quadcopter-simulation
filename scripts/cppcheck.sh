#!/bin/bash

# get repo base directory
# https://stackoverflow.com/a/4774063
PROJ_DIR="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/../"

# deps dirs
EIGEN_INCL=$PROJ_DIR/build/_deps/eigen3-src/
SPDLOG_INCL=$PROJ_DIR/build/_deps/spdlog-src/include/
SPDLOG_SRC=$PROJ_DIR/build/_deps/spdlog-src/src/

# get files to analyze
FILES="`find $PROJ_DIR/src -type f \( -name "*.cpp" \) ! -name "*_test.cpp"`"

# run analysys on files
# make cppcheck build dir
CPPCHECK_BUILD_DIR=$PROJ_DIR/.cppcheck-cache/
mkdir -p $CPPCHECK_BUILD_DIR/

# run cppcheck
# --cppcheck-build-dir  Cache CppCheck data so subsequent runs are fast.
# --inline-suppr  Allow code to add inline suppressions.
# --suppress='noExplicitConstructor'  Ignore the explicit ctor warning, we'll add explicit where required.
# --enable=style  Enable style checks collection. See help docs for what's included.
# --std=c++20  Configure checks for C++20.
# --platform=unix64  Configure checks for UNIX 64-bit architecture.
# --check-level=exhaustive  Use CppCheck to the best of its ability :)
# --error-exitcode=1  Return non-zero error when errors are detected.
cppcheck $FILES \
    --cppcheck-build-dir=$CPPCHECK_BUILD_DIR \
    --inline-suppr \
    --suppress='noExplicitConstructor' \
    --enable=style \
    --std=c++20 \
    --platform=unix64 \
    --check-level=exhaustive \
    --error-exitcode=1 \
    -I $PROJ_DIR/include/ \
    -i $PROJ_DIR/build/ \
    -i $PROJ_DIR/tests/

