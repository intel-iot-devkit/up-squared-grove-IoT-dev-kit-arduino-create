 /*
 created 5 Jun 2013
 by Cristian Maglie
 modified 13 Oct 2017
 by Joseph Butler

 This example code is in the public domain. 
 
 */

/*
  Process
  
  Running linux processes using the Process class.  Gets the Arduino ascii art logo from 
  the network, and prints it over serial.  Also gets the cpu info.

  Make sure to be connected to your board 'via Cloud' for the DebugSerial function to work. If
  you prefer to see the serial output over the micro USB cable, change all instances of DebugSerial
  to Serial.
  
  https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/tree/master/examples/Process

 */

void setup() {
  // Initialize Serial
  DebugSerial.begin(115200);

  // Wait until a Serial Monitor is connected.
  while (!DebugSerial);

  // run various example processes
  runCurl();
  //runCpuInfo();
}

void loop() {
  // Do nothing here.
}

void runCurl() {
  // Launch "curl" command and get Arduino ascii art logo from the network
  // curl is command line program for transferring data using different internet protocols
  Process p;		// Create a process and call it "p"
  p.begin("curl");	// Process that launch the "curl" command
  p.addParameter("-k"); // Add the URL parameter to "curl"  
  p.addParameter("https://www.arduino.cc/asciilogo.txt"); // Add the URL parameter to "curl"
  p.run();		// Run the process and wait for its termination

  // Print arduino logo over the serial
  // A process output can be read with the stream methods
  while (p.available() > 0) {
    char c = p.read();
    DebugSerial.print(c);
  }
  // Ensure the last bit of data is sent.
  DebugSerial.flush();
}

void runCpuInfo() {
  // Launch "cat /proc/cpuinfo" command (shows info on Atheros CPU)
  // cat is a command line utility that shows the content of a file
  Process p;		// Create a process and call it "p"
  p.begin("cat");	// Process that launch the "cat" command
  p.addParameter("/proc/cpuinfo"); // Add the cpuifo file path as parameter to cut
  p.run();		// Run the process and wait for its termination

  // Print command output over serial
  // A process output can be read with the stream methods
  while (p.available() > 0) {
    char c = p.read();
    DebugSerial.print(c);
  }
  // Ensure the last bit of data is sent.
  DebugSerial.flush();
}
