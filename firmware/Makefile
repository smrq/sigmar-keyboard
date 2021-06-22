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

SRCS := definition/keymaps/default/keymap.c \
	definition/config.h \
	definition/sigmar.h \
	definition/sigmar.c \
	definition/rules.mk
TARGET := sigmar_default

all: build/$(TARGET).hex
.PHONY: all build clean docker repl flash
.SECONDARY:

clean:
	$(call RMRF,build)

docker: Dockerfile
	docker build -t $(DOCKER_IMG) .

build/$(TARGET).hex: $(SRCS)
	$(call MKDIRP,build)
	$(RUN) bash -c 'make sigmar:default && cp $(TARGET).hex /root/workspace'

build/eeprom-lefthand.eep build/eeprom-righthand.eep:
	$(call MKDIRP,build)
	$(RUN) bash -c 'cp /root/qmk_firmware/quantum/split_common/*.eep /root/workspace'

flash-left: build/$(TARGET).hex build/eeprom-lefthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash --eeprom build/eeprom-lefthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash build/$(TARGET).hex
	dfu-programmer atmega32u4 reset

flash-right: build/$(TARGET).hex build/eeprom-righthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash --eeprom build/eeprom-righthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash build/$(TARGET).hex
	dfu-programmer atmega32u4 reset
