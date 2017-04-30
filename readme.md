# kuka-rpi-controller

The software package for use with the RPi based ethernet controller box for the UVa Architectural Robotics Research Group.

## Setting up a new RPi

First clone this repository into the home directory. Then run 'setup'. This will install some necessary software and set up the pi to connect with the robot over ethernet.

## Usage

After plugging in the pi, the status LED will turn yellow when ready. Select the program number using the dial, and push it down to select. The status LED will turn green when the program is ready.

Do not unplug the pi when it is running, as this could damage the SD card or other components. Press the red button to reboot the pi, or hold it down for five seconds to power it down. The status LED will turn red to indicate shutdown, and will turn off when safe to unplug. Unplug from the wall socket preferably, to reduce wear on the micro-usb port.

Tools may connect to the pi using the 10-wire ribbon cable. By default, the pi provides 3v3, 5v, Ground, and 7 of the GPIO pins (including those used for the UART and i2c serial protocols). Note that the controller box does not provide voltage or current protection.
Arduinos can also be attached directly over USB, and this may be preferable assuming a suitable long cable.

## Adding new tools

Each tool's code should have its own folder in the tool-files directory. You will also need to edit the startup script so the tool is selectable. At the top, add a new variable in the '#define programs' heading. e.g.
```
# define programs

program_screen = 0
program_vacuum_gripper = 1
...
program_my_program = 4
```

Then under the 'start chosen program heading, add a new elif statement e.g.
```
elif (program_id == program_my_program):
     /home/pi/kuka-rpi-controller/tool-file/my-tool/my-tool-start
     ```