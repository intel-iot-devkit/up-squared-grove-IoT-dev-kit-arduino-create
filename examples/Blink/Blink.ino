/*  
*  Copyright (c) 2017 Intel Corporation.
*  Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Requires a Grove LED connected to the D4 pin on the Grove Pi+ board. 
  
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/Blink
  
*/

//A 512 offset is required for sub-platforms.  516 corresponds to digital pin 4, or D4.
#define LED_BUILTIN 516

// the setup function runs once when you start your sketch
void setup() {
  //add the Grove Pi+ sub-platform
  mraa_add_subplatform(MRAA_GROVEPI, "0");
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
