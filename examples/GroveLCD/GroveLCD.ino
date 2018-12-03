/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Grove LCD

  Example using the Grove LCD UPM library. Prints the value of the analog input from the Grove Rotary Angle Sensor to the display.

  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/GroveLCD

  This sample can be imported into Intel System Studio 2018, Linux hosts only.
  * Free IDE includes optimized libraries, application analysis tools, and debugging tools
  * Import tutorial: https://software.intel.com/en-us/developing-projects-with-intel-system-studio-c-importing-arduino-create-projects
*/

#include "Arduino.h" //not strictly required to run, but prevents erros when importing into Intel(r) System Studio
// upm - Version: Latest 
#include <jhd1313m1.h>
#include "upm_utilities.h"

#define IS_SERIAL_OR_SSH false //Set to false if SSH and set to true if Serial
jhd1313m1_context lcd;

int ndx = 0;
char str[32];
uint8_t rgb[7][3] = {
    {0xd1, 0x00, 0x00},
    {0xff, 0x66, 0x22},
    {0xff, 0xda, 0x21},
    {0x33, 0xdd, 0x00},
    {0x11, 0x33, 0xcc},
    {0x22, 0x00, 0x66},
    {0x33, 0x00, 0x44}};

void setup();
void loop();

void setup() {
    #ifdef IS_SERIAL_OR_SSH
	DebugSerial.begin(9600);
    #endif
    lcd = jhd1313m1_init(0, 0x3e, 0x62);

    if (!lcd) 
	#ifdef IS_SERIAL_OR_SSH
		//print sensor value to the serial monitor
		DebugSerial.println("jhd1313m1_i2c_init() failed.");
	#else
		printf("jhd1313m1_i2c_init() failed.");
	#endif
}

void loop() {
    snprintf(str, sizeof(str), "Hello World %d\0", ndx);
    // Alternate rows on the LCD
    jhd1313m1_set_cursor(lcd, ndx%2, 0);
    jhd1313m1_write(lcd, str, strlen(str));
    // Change the color
    uint8_t r = rgb[ndx%7][0];
    uint8_t g = rgb[ndx%7][1];
    uint8_t b = rgb[ndx%7][2];
    jhd1313m1_set_color(lcd, r, g, b);
    // Echo via DebugSerial
    snprintf(str, sizeof(str), "Hello World %d rgb: 0x%02x%02x%02x\0", ndx++, r, g, b);
    #ifdef IS_SERIAL_OR_SSH
	//print sensor value to the serial monitor
	DebugSerial.println(str);
    #else
	printf("%s",str);
    #endif
    upm_delay(1);
}
