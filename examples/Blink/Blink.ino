/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Requires a Grove LED connected to the Grove Pi+ board. 
  
  The Arduino APIs use MRAA (mraa.io) as a hardware abstraction layer for the UP Squared board.
  The Grove Pi+ is considered a sub-platform in MRAA. For more information see 
  https://github.com/intel-iot-devkit/mraa/blob/master/docs/firmata.md
  
  For information specific to usage of the Grove Pi+ see 
  https://github.com/intel-iot-devkit/mraa/blob/master/docs/grovepi.md
  
  The definition for the Gro
  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
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
