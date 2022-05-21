# Sigmar Keyboard

40% split keyboard design

![IMG_20210816_154000](https://user-images.githubusercontent.com/400889/169670596-53c1943d-756b-4e36-a27f-d207f274645e.jpg)

## Firmware


Prerequisites:

* Install Docker
* Run `make docker` to build the Docker image

Building:

* `make` to build the bootloader and firmware hex files

Flashing the firmware + bootloader:

I had to do it this way because the Teensy 2.0 I used had its bootloader overwritten from a previous project.

* Install [avrdude](https://www.nongnu.org/avrdude/) and make sure it is in your PATH
* Get a Teensy or something running Arduino ISP to serve as a programmer
* Connect the four data lines between the programmer and the target microcontroller
	* Note to self: I did this with a Teensy 2.0 as the target and a spare Teensy 3.1 as the programmer.
	* This works with the stock pin settings for Arduino ISP
	* The data lines to connect are: (programmer -> target)
		* MOSI Pin 11 -> MOSI Pin 2
		* MISO Pin 12 -> MISO Pin 3
		* SCK Pin 13 -> SCK Pin 1
		* Pin 10 -> RESET
* `make flash` to flash the bootloader and firmware.
