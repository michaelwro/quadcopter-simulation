# Define Trick build variable overrides

# multithread build
MAKEFLAGS += -j

# # include paths
TRICK_CFLAGS += -I../include/ -I../src/
TRICK_CXXFLAGS += -I../include/ -I../src/
TRICK_SFLAGS += -I../modules/

# additional options
TRICK_CFLAGS += -std=c11 -Wall -Wextra -Werror -Wpedantic
TRICK_CXXFLAGS += -std=c++11 -Wall -Wextra -Werror -Wpedantic
