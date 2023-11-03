FROM gcc:9.5.0

ENV DEBIAN_FRONTEND=noninteractive
ENV PICO_SDK_PATH=/workspaces/ski-bt-controller/sdk

RUN apt update && apt install -y \
    cmake \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    build-essential \
    libstdc++-arm-none-eabi-newlib