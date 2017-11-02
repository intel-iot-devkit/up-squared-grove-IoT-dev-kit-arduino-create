# Grove Rotary Angle Sensor

## Introduction
You’ll use the serial monitor to see the raw data coming from the sensor. You’ll be able to control the rate of an LED blinking using the input from a rotary angle sensor.

## What you’ll learn
* Stop a sketch that is running
* Set up a serial monitor
* Read analog input data from a sensor
* Use the analog input to control a digital output

## Gather your materials
* [UP2* board](http://www.up-board.org/upsquared)
* [Grove Pi+](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove* Rotary Angle Sensor](http://wiki.seeed.cc/Grove-Rotary_Angle_Sensor)
* [Grove* LED](http://wiki.seeed.cc/Grove-LED_Socket_Kit)

## Stop running sketches
This tutorial assumes you have already set up your board to work with Arduino Create*. If you haven’t done that, go back to the section on [Getting Started](https://software.intel.com/node/e5977984-ca1e-4e58-bbda-76292a51249d).

1. Make sure to stop any running sketches before proceeding with this tutorial. The hardware abstractions layer (MRAA*) locks the hardware pins it is using, so if you try to run a different sketch using those same pins while the previous sketch is still running, it won’t work.

2. To stop running sketches, go to the My Devices page by clicking the menu icon in the upper left and clicking "My Devices". Alternatively, you can go to [https://create-intel.arduino.cc/devices](https://create-intel.arduino.cc/devices).

3. Click "1 SKETCHES RUNNING" 

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=ac9261db-295b-4197-86a9-5c68e56abc4c.png)

4. You should now see the name of the sketch that you ran to blink the LED, for example ‘Blink_mod’. Click "RUNNING".

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=531bf600-b939-40c8-ae03-30a60eae9b57.png)

5. You should now see "STOPPED".

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=b9883f09-80ba-4666-9475-2d4cfac48b19.png)

## Connect hardware
1. Plug in the Grove LED to "D4" on the Grove Pi+ board.

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=414bd27d-3736-4918-ae7e-7bf96c0c393a.jpg)

2. Plug the Grove Rotary Angle Sensor into "A0".

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=6c5e5265-5841-436d-a586-ebb0524ac151.png)

## Get the code
1. To open the example in the Arduino Create IDE, navigate to `Examples > FROM LIBRARIES > UP SQUARED GROVE IOT DEV KIT > GroveRotaryAngle`

**Note**: The rotary angle sensor, also known as a potentiometer, is an analog sensor.

2. Before you upload the example sketch to your board, make sure to open the "Monitor" in Arduino Create. This example outputs the raw analog data values out to the serial monitor.

![](https://software.intel.com/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=e5b6aa4f-2df6-4d7b-b26a-58bc2b8ffad0.png)

3. Upload the example sketch by clicking the "Upload" icon in the upper right of the editor. You should see the LED blink. If you turn the knob on the rotary angle sensor, you can change the rate of the blinking.

If this isn’t working, double-check that you have stopped any other running sketches on the My Devices page [https://create-intel.arduino.cc/devices](https://create-intel.arduino.cc/devices). Once there, if you see an “N Sketches Running” message, "Running" and "Stop" any sketches. If you’ve tried stopping your sketch, but it still doesn’t work, try restarting your UP2 board.

## How it works
You’ll notice that in the code, 512 corresponds to A0 on the Grove Pi+* board, while 516 corresponds to D4. The code doesn’t use 0 or 4 to because you’re required to add an offset of 512 to any pin on the Grove Pi+ board. Why? Under the covers, MRAA (the hardware abstraction library in Arduino) is using the Grove Pi+ board as a sub-platform!So this line to add MRAA_GROVEPI as the sub-platform is required.

`mraa_add_subplatform(MRAA_GROVEPI, "0");`

Whenever you use a sub-platform in MRAA, you need to add an offset of 512 to whatever pin you are using.  For example, if you’re setting the pin mode of a GPIO pin 4, normally your code would look like this: `pinMode(4, OUTPUT);` but with a sub-platform, your code would look like this: `pinMode(516, OUTPUT);`

Digital pins and analog pins both start at zero. Therefore, Analog pin 0 (A0) corresponds to 512, and Digital pin 4 (D4) corresponds to 516. If you’re still unclear how this works, go back to the Blink LED example and read [Understanding How the Code Works](https://software.intel.com/node/d363382b-de12-4019-9c10-c9c89470dd74#Understanding_how_the_code_works) section about MRAA and sub-platforms.

The serial monitor is started in the setup() function: `DebugSerial.begin(115200);`
Data can then be sent using: `DebugSerial.println(sensorValue);`

For more detailed information on how to use the serial monitor, see the [Serial Monitor](https://software.intel.com/node/8d850e2a-d72f-4652-bcbd-254335682b5f) tutorial.

