/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  PWM

  Example using PWM on Arduino Create using UPM.

  Cycles through all PWM output values on a single pin from 0 to 255 and back to 0 over the course of approximately two seconds, then repeats.
  
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/PWMBlink

  This sample can be imported into Intel System Studio 2019 on Linux hosts by using this tutorial
  https://software.intel.com/en-us/developing-projects-with-intel-system-studio-c-importing-arduino-create-projects
*/

#include "Arduino.h" //not strictly required to run, but prevents erros when importing into Intel(r) System Studio

// upm - Version: Latest

#include "upm_utilities.h"

#define LED_PIN 517
//The 512 offset is required for sub-platforms.  517 corresponds to digital pin 5, or D5.
#define DELAY_TIME 4

void setup() {
    //add the Grove Pi+ sub-platform
	mraa_add_subplatform(MRAA_GROVEPI, "0");
	// initialize digital pin LED_PIN as an output.
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
	//brighten
	for (int i = 0; i < 255; i++) {
		analogWrite(LED_PIN, i);
		delay(DELAY_TIME);
	}
	//fade
	for (int i = 255; i > 0; i--) {
		analogWrite(LED_PIN, i);
		delay(DELAY_TIME);
	}
}
