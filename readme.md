# kuka-rpi-controller

The software package for use with the RPi based ethernet controller box for the UVa Architectural Robotics Research Group.

## Usage

After plugging in the pi, the status LED will turn yellow when ready. Select the program number using the dial, and push it down to select. Tool numbers can be found in the 'tools.txt' file. The status LED will turn green when the program is ready. Pressing the dial after this will toggle the board lights on or off. 

Do not unplug the pi when it is running, as this could damage the SD card or other components. Press the red button to reboot the pi, or hold it down for five seconds to power it down. The status LED will turn red to indicate shutdown, and will turn off when safe to unplug. Unplug from the wall side rather than RPi side preferably, to reduce wear on the micro-usb port. Finally, always power down the controller before switching switching tools.

Tools may connect to the pi using the 10-wire ribbon cable. By default, the pi provides 3v3, 5v, Ground, and 7 of the GPIO pins (including those used for the UART and i2c serial protocols). Note that the controller box does not provide voltage or current protection.
Arduinos can also be attached directly over USB, and this may be preferable assuming a suitably long cable.

## Adding new tools

Each tool's code should have its own folder in the tool-files directory. To make a tool selectable, add the name of the its folder to the 'tools.txt' file. At the very least, the tool folder must contain a script called 'start', which will be automatically run when the tool is selected.

Many toolheads will be able to use one of the generic tool programs. generic-digital is a series of on/off switches, similar to the robot's digital IO's but at a lower voltage. generic-uart is basic serial communication; the same method the as an Arduino uses the to send messages back to your computer. generic-i2c is another serial method that allows communication with many devices at once.  

## Setting up a new RPi

If the Pi or SD card breaks or needs to be upgraded, the SD card will need to be restored from backup, or possibly reconfigured entirely. To re-install in a fresh copy of Raspbian, first copy or clone this repository into the home directory. Then enter the following commands:
```
cd ~/kuka-rpi-controller
sh setup
```
This will install some necessary software, configure this software to run at startup, and set up the pi to communicate with the robot or other hardware.

## Internet Access

The network setup is intended to allow wifi usage while manually configuring the ethernet connection to the robot. If unable to connect, you can restore the original network settings with:
`scripts/set-network default`,
and then restore it for robot use when finished:
`scripts/set-network kuka`

Note that the RPi will most likely be unable to connect to the University Wifi system.