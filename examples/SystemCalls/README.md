# System Calls
In this example you’ll learn how to make system calls from Arduino sketches.

System calls are helpful to run commands like you would from a command prompt.  You can use system calls to run scripts, configure the system, copy files, etc.  It is important to note that when running a command from an Arduino\* sketch, the command is run as the root user.

## What you’ll learn
* How to use Linux\* system calls in sketches

## Gather your materials
* UP²\* board

## Get the code
**Examples>FROM LIBRARIES>UP SQUARED GROVE IOT DEV KIT>SerialMonitor>Serial**

Before you upload your example sketch to your board, make sure to open the Monitor in Arduino Create\*.  

After uploading your sketch, you should see the results of the ifconfig command in the Monitor. These results contain your board’s IP address, as shown below.

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=282bcd41-846d-4466-b252-fa9511405d60.png)

## How it works

This example uses the built-in C++ system() library.  Here are two places you can find more information on this library:

http://en.cppreference.com/w/cpp/utility/program/system
http://www.cplusplus.com/reference/cstdlib/system/

Alternatively, you can use Process, the built-in Arduino library, look for the Process example in this repository.
