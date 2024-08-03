FROM ubuntu:22.04

LABEL author "michaelwro"

# deps versions
ARG EIGEN_BRANCH=3.4.0

# create non-root user
ARG USERNAME=user
ARG USER_UID=1000
ARG USER_GID=${USER_UID}

# install base packages
RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    bear build-essential clang clang-format clangd cmake gdb git nano \
    python3-dev python3-pip libspdlog-dev sudo

# install python packages
COPY requirements.txt /opt/
RUN python3 -m pip install -r /opt/requirements.txt --disable-pip-version-check --no-cache-dir

# install Eigen
WORKDIR /usr/local/include/
RUN git clone --branch ${EIGEN_BRANCH} https://gitlab.com/libeigen/eigen.git
RUN ln -sf /usr/local/include/eigen/Eigen Eigen

# create non-root user
# https://code.visualstudio.com/remote/advancedcontainers/add-nonroot-user#_creating-a-nonroot-user
RUN groupadd --gid ${USER_GID} ${USERNAME}
RUN useradd --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME}
RUN echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} \
    && chmod 0440 /etc/sudoers.d/${username}
