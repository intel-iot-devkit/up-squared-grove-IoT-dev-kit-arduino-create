# Grove LCD 
This tutorial shows you how to print 'Hello world' to the LCD display using the UPM library.

## What you'll learn
* How to find the right UPM sensor library for your device
* Instantiate a UPM sensor library class

## Gather your materials
* [UP²\* board](http://www.up-board.org/upsquared)
* [GrovePi+](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove\* LCD RGB Backlight](https://www.seeedstudio.com/Grove-LCD-RGB-Backlight-p-1643.html)

## Setup
Plug the Grove LCD RGB Backlight into any I2C port.  

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
