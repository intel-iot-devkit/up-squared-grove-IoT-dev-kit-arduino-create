/*  
*  Copyright (c) 2017 Intel Corporation.
*  Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Grove Rotary Angle

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 4.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead(). Also demonstrates the use of the serial port with the DebugSerial function.
  An offset of 512 is applied because the Grove Pi+ board is a subsystem.  See the Blink example 
  for more details.

  Make sure to be connected to your board 'via Cloud' for the DebugSerial function to work. If
  you prefer to see the serial output over the micro USB cable, change all instances of DebugSerial
  to Serial.

  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/GroveRotaryAngle 
  
*/


int sensorPin = 512;    // select the input pin for the Grove rotary angle sensor
int ledPin = 516;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // add the Grove Pi+ sub-platform
  mraa_add_subplatform(MRAA_GROVEPI, "0");
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  // Setup serial terminal, meant for devices connected via Cloud.  If you are using the UP^2 board via serial port (COM, tty, etc)
  // change the DebugSerial method with Serial in all instances
  DebugSerial.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // print sensor value to the serial monitor
  DebugSerial.println(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
