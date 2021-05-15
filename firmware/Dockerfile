FROM python:3

RUN apt-get -y update \
  && apt-get install -y binutils-avr gcc-avr avr-libc \
  && rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install qmk

WORKDIR /root
RUN git clone --recurse-submodules https://github.com/qmk/qmk_firmware.git

WORKDIR /root/qmk_firmware
