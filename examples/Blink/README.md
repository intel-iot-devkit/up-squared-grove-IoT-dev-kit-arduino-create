
# Introduction

# What you'll learn
In this step, you will:
* Connect an LED
* Open the sample Blink application
* Modify the sketch for your board
* Upload your sketch using Arduino Create\*
* Dig into the code

# Gather your materials

## Connect an LED
1. Locate the Grove* Green LED in your Grove kit and use a Grove* Cable to connect it to on your Grove Pi+* board. It’s ok to leave your board on when plugging in the LED.
<img> 

You may need to first plug the LED into the terminals on the Grove LED module; if so, be sure to connect the longer wire to the positive terminal.

## Open the Sample Blink application
1. If it's not open already, open the [Arduino Web Editor](https://create-intel.arduino.cc/editor)
2. Open the Blink example made specifically for this kit. You can find it in `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > Blink` 
<img>

## Upload your Sketch Using Arduino Create*
1. Choose your board, "via Cloud"<img>

Click the "Upload" icon to upload and run the sketch.

<img>
**Note**: When you click "Upload" button <img> you're uploading and running the sketch on your target device. To compile your sketch without uploading and running it, click the "Verify" button <img> to the left of the "Upload" icon.

## Stopping and Starting Sketches
Now that your sketch is running, we’ll show you how to stop it.  

1. Go to the My Devices page by clicking the menu icon in the upper left and clicking My Devices. Alternatively, you can go to https://create.arduino.cc/devices.

2. Click ‘1 SKETCHES RUNNING’
<img>
You should now see the name of the sketch that you ran to blink the LED, for example ‘Blink_mod’. Click on ‘RUNNING’

You should now see ‘STOPPED’
<img>

## Your sketch is running
1. You can confirm that your sketch is running because the log at the bottom of the screen gives you a Process ID (PID). For example:
<img>

2. You should see the LED flashing.
<img>

If your LED isn't flashing, check the following:
* You have connected the LED to the right connector on the Grove Pi+ board
* Make sure the board you have selected is the one that says "via Cloud"
* Your board is still connected. You can see this in the My Devices page [https://create-intel.arduino.cc/devices](https://create-intel.arduino.cc/devices). It should say ONLINE. If it isn’t, check the network connections. If all else fails and your board continues OFFLINE, go through the setup process again, starting at [Create an account and install the Arduino plugin](https://software.intel.com/node/8c6e7d82-619d-4e04-b4d7-0ea54b10e46f).
* Make sure the LED is plugged in the right way (the longer wire should be connected to the positive terminal). Try another LED if you have one.
## Digging into the code

You may have seen some lines in the code that you don’t recognize. Before we dive in, there are a couple of concepts to understand:
* MRAA* (mraa.io) – pronounced ‘em rah’ is the hardware abstraction layer in Arduino Create for Linux*-based platforms. It is an open source project, and it supports multiple boards and programming languages. Using MRAA allows you to initialize and work with pins on a board with an easy-to-understand API.

* Platform – The way that MRAA abstracts the hardware is through a pin mapping at the user space level. So when you use MRAA, you need to set your platform so the mapping is done correctly for your specific board.  In this case, the platform is the UP² board, but MRAA supports over a dozen boards. You can see a complete list of the pin mapping here: [https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/blob/master/extras/pin-mapping.md](https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/blob/master/extras/pin-mapping.md)

MRAA supports GPIO, I2C, PWM, SPI, and UART. There is also a very useful library written on top of MRAA which is an abstraction for individual sensors.  It’s called UPM and you can read about it at [https://upm.mraa.io/](https://upm.mraa.io). UPM is supported in Arduino Create for platforms using MRAA.

* Sub-platform – When using MRAA, you have the option to define a sub-platform. A sub-platform operates with the same APIs as the platform, but you are required to add an offset of 512 to all pins.  Note that you can only have one sub-platform for each application using MRAA. The most common reason to use a sub-platform is to expand the I/O capabilities of a platform. In this guide, the Grove Pi+ board provides easy to use connectors for the Grove sensors, a handy addition to the UP² board. On the Grove Pi+ board is an ATMEL ATMEGA 328, which gets programmed by MRAA with a Firmata* sketch when you try to run it as a sub-platform. The Firmata sketch running on the ATMEGA acts as sort of a slave, interpreting commands from the platform (MRAA application running on the UP² board) and passing data back and forth between the I/Os and the platform. The sub-platform is controlled via I2C (though it can also be done over serial).

## Get the Code

```#define LED_BUILTIN 516```

Since the Grove Pi+ board is a sub-platform of the UP² board, we need to offset the pin numbers by 512.  Since the LED is connected to D4, the pin number we need to use is 4 plus the offset of 512, which is 516.

## How it Works
Digital pins and analog pins both start at zero. For example, Analog pin 0 (A0) corresponds to 512, and Digital pin 4 (D4) corresponds to 516.

```mraa_add_subplatform(MRAA_GROVEPI, "0")```

This line adds the Grove Pi+ board as a sub-platform.
The rest of the code uses the standard Arduino APIs.
* [PinMode](https://www.arduino.cc/en/Reference/PinMode)
* [DigitalWrite](https://www.arduino.cc/en/Reference/DigitalWrite)
* [Delay](https://www.arduino.cc/en/Reference/Delay)

## Next Steps
Now that your board is connected to Arduino Create, continue on to the tutorials.
All our tutorials are located in github at https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples and can be accessed in the IDE in `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT`

These tutorials generally fall into four categories:
* Computer vision with OpenCV
* Sensors and the Grove Pi+ board using mraa and upm
* Cloud connectivity using MQTT
* Utilities like SerialMonitor, Process, and SystemCalls

If you’re not sure where to start, we recommend learning the basics about sensors with the [GroveRotaryAngle](https://software.intel.com/node/b7b16e2f-9d80-45fe-ada1-93ddb65759aa) tutorial.

