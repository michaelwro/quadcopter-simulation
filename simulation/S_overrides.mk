# Define Trick build variable overrides

# multithread build
MAKEFLAGS += -j

# # include paths
# TRICK_CFLAGS += -I ./
# TRICK_CXXFLAGS += -I ./
# TRICK_SFLAGS += -I ./

# other C/C++ flags
# NOTE: Trick is developed with c++11
TRICK_CFLAGS += -std=c11
TRICK_CXXFLAGS += -std=c++11
