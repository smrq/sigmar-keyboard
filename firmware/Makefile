CWD := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

ifeq ($(OS),Windows_NT)
	REVERSE_SLASHES = $(subst /,\,$1)
	MKDIRP = if not exist $(call REVERSE_SLASHES,$1) (mkdir $(call REVERSE_SLASHES,$1))
	RMRF = if exist $(call REVERSE_SLASHES,$1) (rmdir /s /q $(call REVERSE_SLASHES,$1))
else
	MKDIRP = mkdir -p $1
	RMRF = rm -rf $1
endif

DOCKER_IMG := sigmar-firmware
RUN := docker run --rm -v $(CWD)definition:/root/qmk_firmware/keyboards/sigmar -v $(CWD)build:/root/workspace $(DOCKER_IMG) 

PORT := /dev/tty.usbmodem8076901

all: build/sigmar_default_production.hex
.PHONY: all clean docker
.SECONDARY:

clean:
	$(call RMRF,build)

docker: Dockerfile
	docker build -t $(DOCKER_IMG) .

build/sigmar_default_production.hex:
	$(call MKDIRP,build)
	$(RUN) bash -c 'make sigmar:default:production && cp sigmar_default_production.hex /root/workspace'

flash: build/sigmar_default_production.hex
	avrdude -p atmega32u4 -c arduino -P $(PORT) -v -U flash:w:build/sigmar_default_production.hex
