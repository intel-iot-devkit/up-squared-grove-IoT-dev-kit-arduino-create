/*  
*  Copyright (c) 2017 Intel Corporation.
*  Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Serial
  Learn how to set up a serial monitor. You’ll use built-in functions to set up, transmit, and receive data over serial, which is very useful for debugging.
  
  Make sure you open the Monitor after uploading this sketch.  Serial only works on UP Squared devices connected over micro USB.
  
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/SerialMonitor/Serial
  
*/

int incomingByte = 0;   // for incoming serial data
void setup() {
        Serial.begin(115200);     // opens serial port, sets data rate to 115200 bps
}
void loop() {
        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }
}
