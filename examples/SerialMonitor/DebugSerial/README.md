# DebugSerial
This tutorial shows you how to use the DebugSerial function over the USB port of your UP Squared.  The DebugSerial function will only work if your UP Squared is connected 'via Cloud'.  If you are connected via micro USB cable, then see this [Serial](./../Serial) tutorial.

## What you'll learn 
* Setup the serial monitor

## Gather your materials
* UP Squared board connected 'via Cloud'

## Setup
Make sure your UP Squared board shows up as a device in the editor 'via Cloud'

## Get the code
**Examples>FROM LIBRARIES>UP SQUARED GROVE IOT DEV KIT>SerialMonitor>DebugSerial**

## How it works
DebugSerial sends data over the cloud from your device.  Even though it's called a serial terminal, it really doesn't matter what baud rate you set it to.  

It's important to know that running multiple sketches that use DebugSerial is possible, and all the results from the same device will show up in the Monitor at the same time.
