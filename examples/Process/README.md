# Process
This tutorial walks you through running Linux\* processes using the Process class. It gets the Arduino\* ascii art logo from the network, and prints it over serial.  It also gets and prints the cpu info.

## What you'll learn
* How to pass parameters to your processes 
* How to spawn processes using the Process class

## Gather your materials
You’ll need the following to complete this tutorial:
* ![UP² board](http://www.up-board.org/upsquared/) 

## Setup
Install curl before running since it isn't installed on the image that's shipped with the kit.

```
sudo apt-get install curl
```

## Get the code
This example is located in **EXAMPLES > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > Process**

## How it works
Process is a class built for the Arduino Yun that also works nicely on the UPSquared.  It is a built-in class so there is nothing to include.  More about the class can be found at https://www.arduino.cc/en/Reference/YunProcessConstructor 

The basic way to use it is as follows:

```
Process <name>
<name>.begin("<command>")
<name>.addParameter ("<parameter1>")
<name>.addParameter ("<parameter2>")
etc
<name>.run()
```
IMPORTANT NOTICE: This software is sample software. It is not designed or intended for use in any medical, life-saving or life-sustaining systems, transportation systems, nuclear systems, or for any other mission-critical application in which the failure of the system could lead to critical injury or death. The software may not be fully tested and may contain bugs or errors; it may not be intended or suitable for commercial release. No regulatory approvals for the software have been obtained, and therefore software may not be certified for use in certain countries or environments.
