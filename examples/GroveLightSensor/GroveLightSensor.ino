/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Grove LCD

  Example using the Grove Light Sensor. **DESCRIPTION**

  **LINK**
*/

#include "upm_utilities.h"

#define SENSOR_PIN 512
#define DELAY_MS 500

void setup() {
	// add the Grove Pi+ sub-platform
	mraa_add_subplatform(MRAA_GROVEPI, "0");
	DebugSerial.begin(9600);
}

void loop() {
	DebugSerial.println(analogRead(SENSOR_PIN));
	delay(DELAY_MS);
}