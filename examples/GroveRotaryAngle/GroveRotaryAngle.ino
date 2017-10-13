/*
  Rotary Angle

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 4.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  Also demonstrates the use of the serial port with the DebugSerial method.
  
  An offset of 512 is applied because the Grove Pi+ board is a subsystem.  See the Blink example 
  for more details.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInput
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
