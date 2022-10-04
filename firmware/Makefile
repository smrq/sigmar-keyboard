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
RUN := podman run --rm -v $(CWD)definition:/root/qmk_firmware/keyboards/sigmar -v $(CWD)build:/root/workspace $(DOCKER_IMG)

SRCS_COMMON := definition/config.h definition/sigmar.h definition/sigmar.c definition/rules.mk
SRCS_OSX := definition/keymaps/osx/config.h definition/keymaps/osx/keymap.c definition/keymaps/osx/rules.mk
SRCS_WINDOWS := definition/keymaps/windows/config.h definition/keymaps/windows/keymap.c definition/keymaps/windows/rules.mk

all: build/sigmar_osx.hex build/sigmar_windows.hex
.PHONY: all build clean docker flash-left flash-right
.SECONDARY:

clean:
	$(call RMRF,build)

docker: Dockerfile
	podman build -t $(DOCKER_IMG) .

build/sigmar_osx.hex: $(SRCS_COMMON) $(SRCS_OSX)
	$(call MKDIRP,build)
	$(RUN) bash -c 'make sigmar:osx && cp sigmar_osx.hex /root/workspace'

build/sigmar_windows.hex: $(SRCS_COMMON) $(SRCS_WINDOWS)
	$(call MKDIRP,build)
	$(RUN) bash -c 'make sigmar:windows && cp sigmar_windows.hex /root/workspace'

build/sigmar_osx_bootloader.hex: $(SRCS_COMMON) $(SRCS_OSX)
	$(call MKDIRP,build)
	$(RUN) bash -c 'make sigmar:osx:bootloader && cp sigmar_osx_bootloader.hex /root/workspace'

build/sigmar_windows_bootloader.hex: $(SRCS_COMMON) $(SRCS_WINDOWS)
	$(call MKDIRP,build)
	$(RUN) bash -c 'make sigmar:windows:bootloader && cp sigmar_windows_bootloader.hex /root/workspace'

build/eeprom-lefthand.eep build/eeprom-righthand.eep:
	$(call MKDIRP,build)
	$(RUN) bash -c 'cp /root/qmk_firmware/quantum/split_common/*.eep /root/workspace'

flash-left: build/sigmar_osx.hex build/eeprom-lefthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash-eeprom build/eeprom-lefthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash build/sigmar_osx.hex
	dfu-programmer atmega32u4 reset

flash-right: build/sigmar_windows.hex build/eeprom-righthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash-eeprom build/eeprom-righthand.eep
	dfu-programmer atmega32u4 erase
	dfu-programmer atmega32u4 flash build/sigmar_windows.hex
	dfu-programmer atmega32u4 reset
