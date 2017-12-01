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
	 mraa_add_subplatform(MRAA_GROVEPI, "0");
}

void loop() {
	for (int i = 0; i < 1023; i++) {
		analogWrite(LED_PIN, i);
		upm_delay_ms(DELAY_TIME);
	}
	for (int i = 1023, i > 0; i--) {
		analogWrite(LED_PIN, i);
		upm_delay_ms(DELAY_TIME);
	}
}