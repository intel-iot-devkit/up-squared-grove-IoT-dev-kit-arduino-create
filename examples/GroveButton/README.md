# Grove Button
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

This tutorial shows you how to use the Grove button with Arduino Create on the Up² board.

## What you'll learn
* How to use the Grove button via the GrovePi+.

## Gather your materials
* [UP²\* board](http://www.up-board.org/upsquared)
* [GrovePi+](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove\* Button](https://www.seeedstudio.com/Grove-Button-p-766.html)

## Setup
Plug the Grove button into port D4.

## Get the code
This example can be found in the Arduino Create IDE under `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > GroveButton`.

Before running, open the Monitor in the IDE.

After running should see `Pressed!` and `Released!` in the Monitor when you push the button.

## How it works
When otherwise idle, the loop continuously listens for input on the button. Upon being pressed, a message is logged and execution shifts into an internal loop, which effectively pauses execution until the button is released, causing another message to be displayed. At this point the execution returns to its default idle state.