# Grove Light Sensor
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

This tutorial shows you how to use the Grove Light Sensor with Arduino Create on the Up² board.

## What you'll learn
* How to use the Grove light sensor via the GrovePi+.

## Gather your materials
* [UP²\* board](http://www.up-board.org/upsquared)
* [GrovePi+](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove\* Light Sensor](https://www.seeedstudio.com/Grove-Light-Sensor-v1.2-p-2727.html)

## Setup
Plug the Grove light sensor into port A0.

## Get the code
This example can be found in the Arduino Create IDE under `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > GroveLightSensor`.

Before running, open the Monitor in the IDE.

After running should see the value of the sensor input in the Monitor.


## How it works
On each loop interval, the light sensor is queried for the current light level, which is then displayed as an integer from 0 to 1024 on the debug serial terminal. A simple delay is also added to prevent looping too quickly.