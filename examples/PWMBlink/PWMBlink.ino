/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  PWM

  Example using PWM on Arduino Create using UPM.

  Cycles through all PWM output values on a single pin from 0 to 255 and back to 0 over the course of approximately two seconds, then repeats.

*/

// upm - Version: Latest

#include "upm_utilities.h"

#define LED_PIN 517
#define DELAY_TIME 4

void setup() {
	pinMode(LED_PIN, OUTPUT);
	mraa_add_subplatform(MRAA_GROVEPI, "0");
}

void loop() {
	for (int i = 0; i < 255; i++) {
		analogWrite(LED_PIN, i);
		delay(DELAY_TIME);
	}
	for (int i = 255; i > 0; i--) {
		analogWrite(LED_PIN, i);
		delay(DELAY_TIME);
	}
}