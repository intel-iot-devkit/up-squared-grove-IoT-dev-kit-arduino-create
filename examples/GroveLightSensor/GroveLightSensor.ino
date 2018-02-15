/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Grove Light Sensor

  Example using the Grove Light Sensor. 
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/GroveLightSensor
*/

#include "Arduino.h" //not strictly required to run, but prevents erros when importing into Intel(r) System Studio
#include "upm_utilities.h"

//A 512 offset is required for sub-platforms.  512 corresponds to analog pin 0, or A0.
#define SENSOR_PIN 512
#define DELAY_MS 500

void setup() {
	// add the Grove Pi+ sub-platform
	mraa_add_subplatform(MRAA_GROVEPI, "0");
	// DebugSerial should be used via cloud (when you don't have the micro USB cable connected)
	DebugSerial.begin(9600);
}

void loop() {
	//read analog value from light sensor and print via serial
	DebugSerial.println(analogRead(SENSOR_PIN));
	delay(DELAY_MS);
}