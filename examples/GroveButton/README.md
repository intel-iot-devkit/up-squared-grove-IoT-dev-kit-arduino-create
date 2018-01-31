# Grove LCD
This tutorial shows you how to use the Grove button with Arduino Create on the Up² board.

## What you'll learn
* How to use the Grove button via the GrovePi+.

## Gather your materials
* [UP²\* board](http://www.up-board.org/upsquared)
* [GrovePi+](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove\* Button](https://www.seeedstudio.com/Grove-Button-p-766.html)

## Setup
Plug the Grove button into port D4.

## How it works
When otherwise idle, the loop continuously listens for input on the button. Upon being pressed, a message is logged and execution shifts into an internal loop, which effectively pauses execution until the button is released, causing another message to be displayed. At this point the execution returns to its default idle state.