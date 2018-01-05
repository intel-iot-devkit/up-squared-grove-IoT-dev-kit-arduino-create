# Grove LCD
This tutorial shows you how to use the Grove light sensor with Arduino Create on the Up² board.

## What you'll learn
* How to use the Grove light sensor via the GrovePi+.

## Gather your materials
* [UP²\* board](http://www.up-board.org/upsquared)
* [GrovePi+](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove\* Light Sensor](https://www.seeedstudio.com/Grove-Light-Sensor-v1.2-p-2727.html)

## Setup
Plug the Grove light sensor into port A0.

## How it works
On each loop interval, the light sensor is queried for the current light level, which is then displayed as an integer from 0 to 1024 on the debug serial terminal. A simple delay is also added to prevent looping too quickly.