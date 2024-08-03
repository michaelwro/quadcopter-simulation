# Define Trick build variable overrides

# get the current path
THIS_DIR=$(abspath $(dir $(lastword $(MAKEFILE_LIST))))

# multithread build
MAKEFLAGS += -j

# # include paths
TRICK_CFLAGS += -I${THIS_DIR}/../include/ -I${THIS_DIR}/../src/
TRICK_CXXFLAGS += -I${THIS_DIR}/../include/ -I${THIS_DIR}/../src/
TRICK_SFLAGS += -I${THIS_DIR}/../modules/

# additional options
TRICK_CFLAGS += -std=c11 -Wall -Wextra -Werror -Wpedantic
TRICK_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -Wpedantic
