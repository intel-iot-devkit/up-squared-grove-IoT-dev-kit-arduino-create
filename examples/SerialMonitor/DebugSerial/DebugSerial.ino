/*  
*  Copyright (c) 2017 Intel Corporation.
*  Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  DebugSerial
  Learn how to set up a serial monitor. You’ll use built-in functions to set up, transmit, and receive data over serial, which is very useful for debugging.
  
  Make sure you open the Monitor after uploading this sketch.  DebugSerial only works on devices connected 'via Cloud'
  
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/SerialMonitor/DebugSerial
  
  This sample can be imported into Intel System Studio 2019 on Linux hosts by using this tutorial
  https://software.intel.com/en-us/developing-projects-with-intel-system-studio-c-importing-arduino-create-projects
*/

#include "Arduino.h" //not strictly required to run, but prevents erros when importing into Intel(r) System Studio

int incomingByte = 0;   // for incoming serial data
void setup() {
        DebugSerial.begin(115200);     // opens serial port, sets data rate to 115200 bps
}
void loop() {
        // send data only when you receive data:
        if (DebugSerial.available() > 0) {
                // read the incoming byte:
                incomingByte = DebugSerial.read();
                // say what you got:
                DebugSerial.print("I received: ");
                DebugSerial.println(incomingByte, DEC);
        }
}
