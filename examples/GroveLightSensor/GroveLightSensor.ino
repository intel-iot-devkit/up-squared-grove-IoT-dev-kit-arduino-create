/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Grove Light Sensor

  Example using the Grove Light Sensor. 
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/GroveLightSensor

  This sample can be imported into Intel System Studio 2018, Linux hosts only.
  * Free IDE includes optimized libraries, application analysis tools, and debugging tools
  * Import tutorial: https://software.intel.com/en-us/developing-projects-with-intel-system-studio-c-importing-arduino-create-projects
 */

#include "Arduino.h" //not strictly required to run, but prevents erros when importing into Intel(r) System Studio
#include "upm_utilities.h"

//Set to false if SSH and set to true if Serial Connection
#define IS_SERIAL_OR_SSH true
//A 512 offset is required for sub-platforms.  512 corresponds to analog pin 0, or A0.
#define SENSOR_PIN 512
#define DELAY_MS 500

void setup() {
	// add the Grove Pi+ sub-platform
	mraa_add_subplatform(MRAA_GROVEPI, "0");
	// DebugSerial should be used via cloud (when you don't have the micro USB cable connected)
	#ifdef IS_SERIAL_OR_SSH
		DebugSerial.begin(9600);
	#endif
}

void loop() {
	//read analog value from light sensor and print via serial
	#ifdef IS_SERIAL_OR_SSH
		DebugSerial.println(analogRead(SENSOR_PIN));
	#else
		printf("%d\n",(analogRead(SENSOR_PIN)));
	#endif
	delay(DELAY_MS);
}
