/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
	Grove Button

	Example using the Grove Button. Prints to the debug serial terminal when the button is pressed.
	https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/GroveButton

	This sample can be imported into Intel System Studio 2018, Linux hosts only.
	* Free IDE includes optimized libraries, application analysis tools, and debugging tools
	* Import tutorial: https://software.intel.com/en-us/developing-projects-with-intel-system-studio-c-importing-arduino-create-projects
*/

#include "Arduino.h" //not strictly required to run, but prevents erros when importing into Intel(r) System Studio
// upm - Version: Latest 
#include "upm_utilities.h"

//A 512 offset is required for sub-platforms.  516 corresponds to digital pin 4, or D4.
#define BUTTON_PIN 516

void setup() {
    //add the Grove Pi+ sub-platform
	mraa_add_subplatform(MRAA_GROVEPI, "0");
	// initialize digital pin BUTTON_PIN as an input.
	pinMode(BUTTON_PIN, INPUT);
	// DebugSerial should be used via cloud (when you don't have the micro USB cable connected)
	DebugSerial.begin(9600);
}

void loop() {
	//check for a high from the button, once it is released print 'Released!'
	if (digitalRead(BUTTON_PIN)) {
		DebugSerial.println("Pressed!");
		while (digitalRead(BUTTON_PIN));
		DebugSerial.println("Released!");
	}
}