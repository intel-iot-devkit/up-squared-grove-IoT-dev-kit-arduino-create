# Grove\* LCD
<table>
	<tr>
		<td>Programming language</td>
		<td>C++ (Arduino)</td>
	</tr>
	<tr>
		<td>Skill level</td>
		<td>Beginner</td>
	</tr>
	<tr>
		<td>Time to complete</td>
		<td>5 minutes</td>
	</tr>
	<tr>
		<td>Hardware needed</td>
		<td>UP Squared Grove IoT Development Kit</td>
	</tr>
	<tr>
		<td>Target Operating System</td>
		<td>Ubuntu 16.04</td>
	</tr>
</table>

This tutorial demonstrates how to print "Hello World" to an LCD display using the UPM library.

## What you'll learn
* How to find the correct UPM sensor library for your device
* Instantiate a UPM sensor library class

## Gather your materials
* [UP Squared* board](http://www.up-board.org/upsquared)
* [GrovePi+\*](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove\* LCD RGB Backlight](https://www.seeedstudio.com/Grove-LCD-RGB-Backlight-p-1643.html)

## Setup
Plug the Grove LCD RGB Backlight into any available I2C port on the GrovePi+.  
![LCD Sensor](../../extras/LCD_0.jpg)

## Get the code
This example can be found in the Arduino Create IDE under `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > GroveLCD`.

### Expected output
Before running, open the Monitor in the IDE.

After running should see `Hello world X` and the value of X should be incrementing.
![Arduino Create IDE](../../extras/LCD_2.png)

![Hello World](../../extras/LCD_1.jpg)

## How it works
In order for any UPM library to work, you need to include the header file corresponding to that particular sensor in your sketch. Unfortunately, if you browse the Libraries in Arduino Create\* and include the UPM library, all the UPM sensor libraries will be included, and you probably only need one or two out of the several hundred.

The solution is to find your sensor first in the list https://iotdk.intel.com/docs/master/upm/modules.html 

Then copy the name of the .h file.

**Note: UPM libraries are generally defined by part number**

At the top of your sketch include it, for example:
```
#include <jhd1313m1.h>
```
To instantiate:
```
jhd1313m1_context lcd = jhd1313m1_init(0, 0x3e, 0x62);
```

For a full list of examples see https://github.com/intel-iot-devkit/upm/tree/master/examples/c%2B%2B 


IMPORTANT NOTICE: This software is sample software. It is not designed or intended for use in any medical, life-saving or life-sustaining systems, transportation systems, nuclear systems, or for any other mission-critical application in which the failure of the system could lead to critical injury or death. The software may not be fully tested and may contain bugs or errors; it may not be intended or suitable for commercial release. No regulatory approvals for the software have been obtained, and therefore software may not be certified for use in certain countries or environments. 
