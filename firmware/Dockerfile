FROM python:3

RUN apt-get -y update && \
  apt-get install -y sudo && \
  rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install qmk

WORKDIR /root
RUN qmk clone

WORKDIR /root/qmk_firmware
RUN apt-get -y update && \
  ./util/qmk_install.sh && \
  rm -rf /var/lib/apt/lists/*
