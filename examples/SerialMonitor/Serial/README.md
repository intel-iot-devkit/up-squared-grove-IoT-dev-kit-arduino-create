# Serial
This tutorial shows you how to use the Serial function over the USB port of your UP Squared.  The Serial function will only work if your UP Squared is connected over the micro USB cable.  If you are connected via Cloud, then see this [DebugSerial](./../DebugSerial) tutorial.

## What you'll learn 
* Setup the serial monitor

## Gather your materials
* UP Squared board
* micro USB cable

## Setup
Plug the micro USB cable into your UP Squared board and your host computer and verify your board shows up as a device in the editor.

## Get the code
**Examples>FROM LIBRARIES>UP SQUARED GROVE IOT DEV KIT>SerialMonitor>Serial**

## How it works
Serial sends data over the USB cable from your device. Unlike with DebugSerial, baud rate does matter, so stick with 115200.

Using Serial is ideal for situations where you are offline or you may want a lower latency since it's not going through the cloud.
