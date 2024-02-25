#!/bin/bash

# project directory
PROJ_DIR="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )/../"

# build and output compile commands
cd $PROJ_DIR/simulation/
bear --append --output ../compile_commands.json -- trick-CP
