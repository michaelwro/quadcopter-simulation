FROM ubuntu:22.04

LABEL author "michaelwro"

# NASA Trick commit/release tag
ARG TRICK_TAG=19.7.1

# install NASA Trick deps and a few others
# deps identifed at https://nasa.github.io/trick/documentation/install_guide/Install-Guide#ubuntu
# see next step about the addition of `locales` to the list
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y bison clang flex git llvm make maven swig cmake \
    curl g++ libx11-dev libxml2-dev libxt-dev libmotif-common libmotif-dev \
    python3-dev zlib1g-dev llvm-dev libclang-dev libudunits2-dev \
    libgtest-dev openjdk-11-jdk zip locales

# fix perl-related locale warnings
# https://askubuntu.com/questions/114759/warning-setlocale-lc-all-cannot-change-locale/114781#114781
# https://libre-software.net/linux-server/ubuntu-setting-locale/
RUN locale-gen en_US.UTF-8
RUN update-locale LANG=en_US.UTF-8

# install other deps
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y \
    sudo clang-format python3-pip gdb nano bear clangd-15

# build and install NASA Trick
ENV PYTHON_VERSION=3
WORKDIR /opt
RUN git clone --branch=${TRICK_TAG} https://github.com/nasa/trick.git

WORKDIR /opt/trick/
RUN ./configure
RUN make -j$((`nproc`/2 <= 1 ? 1 : `nproc`/2))
RUN make install

ENV TRICK_HOME=/opt/trick/
