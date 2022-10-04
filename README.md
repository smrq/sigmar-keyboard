# Sigmar Keyboard

40% split keyboard design

![IMG_20210816_154000](https://user-images.githubusercontent.com/400889/169670596-53c1943d-756b-4e36-a27f-d207f274645e.jpg)

## PCB

The design for the PCB was done in KiCad. The PCB is designed according to the specifications of manufacturing with [JLCPCB](https://jlcpcb.com/).


## Firmware

Prerequisites:

* Podman
* dfu-programmer

Building:

* `make docker` to build the container image
* `make` to build the bootloader and firmware hex files

Flashing:

* `make flash left` or `make flash right`

### Building and flashing in WSL

* Install Ubuntu >= 22.04
* Install usbipd-win
* `sudo apt install dfu-programmer podman`

Flashing:

* In Powershell
	- `usbipd list`
		- Find the entry that corresponds with the keyboard (when in keyboard mode, VID/PID is f055:5164)
	- Press the reset button to switch to flashing mode
		- You will need another keyboard or the on-screen virtual keyboard from now on! If the latter, it might help to type the following commands beforehand, so you only need to press enter.
	- `usbipd wsl attach --busid=#-##`

* In WSL
	- `make flash-left` or `make flash-right`

### Flashing the bootloader with Arduino ISP

* Connect Arduino ISP
	* MOSI Pin 11 (programmer) -> B2 (target)
	* MISO Pin 12 -> B3
	* SCK Pin 13 -> B1
	* RST Pin 10 -> RST
* `make build/sigmar_[osx|windows]_bootloader.hex`
* `avrdude -p atmega32u4 -F -P COM4 -c stk500v1 -b 19200 -U flash:w:build/sigmar_[osx|windows]_bootloader.hex`
	* `-P COM4` should match the serial port for the Arduino ISP
