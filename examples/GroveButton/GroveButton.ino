/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
	Grove Button

	Example using the Grove Button. Prints to the debug serial terminal when the button is pressed.
*/

// upm - Version: Latest 
#include "upm_utilities.h"

#define BUTTON_PIN 516

void setup() {
	mraa_add_subplatform(MRAA_GROVEPI, "0");
	pinMode(BUTTON_PIN, INPUT);
	DebugSerial.begin(9600);
}

void loop() {
	if (digitalRead(BUTTON_PIN)) {
		DebugSerial.println("Pressed!");
		while (digitalRead(BUTTON_PIN));
		DebugSerial.println("Released!");
	}
}