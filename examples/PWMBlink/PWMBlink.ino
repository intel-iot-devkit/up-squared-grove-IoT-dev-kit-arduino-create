/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  PWM

  Example using PWM on Arduino Create using UPM.

  Cycles through all PWM output values on a single pin from 0 to 1024 and back to 0 over the course of approximately four seconds, then repeats.

*/

// upm - Version: Latest

#include "upm_utilities.h"

#define LED_PIN 516
#define DELAY_TIME 2

void setup() {
	mraa_add_subplatform(MRAA_GENERIC_FIRMATA, "/dev/ttyS1"); //For testing. This is the way it's done in another example, but in others it's (MRAA_GROVEPI, "0"). I don't know which is correct, so I'm testing both.
}

void loop() {
	for (int i = 0; i < 1023; i++) {
		analogWrite(LED_PIN, i);
		delay(DELAY_TIME);
	}
	for (int i = 1023; i > 0; i--) {
		analogWrite(LED_PIN, i);
		delay(DELAY_TIME);
	}
}