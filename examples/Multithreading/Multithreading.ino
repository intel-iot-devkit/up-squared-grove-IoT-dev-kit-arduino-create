/* Copyright (c) Intel. All rights reserved.
Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

/*
  Multithreading

  Example using multithreading on Arduino Create.

  Prints out a string from each thread at different intervals.
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/Multithreading

*/


#include <sys/types.h>
#include <unistd.h>

pid_t pid = 0;
unsigned int count1 = 0,
	count2 = 0;

void setup() {
	DebugSerial.begin(9600);
	pid = fork();
}

void loop() {
	if (pid != 0) { //Parent process.
		DebugSerial.print("Hello from the parent process! " + String(count1) + "\n");
		count1++;
		delay(2000);
	}
	else if (pid == 0) { //Child process.
		DebugSerial.print("Hello from the child process! " + String(count2) + "\n");
		count2++;
		delay(1000);
	}
}