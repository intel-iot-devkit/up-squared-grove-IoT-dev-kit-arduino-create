# Grove Rotary Angle Sensor

# Introduction
You’ll use the serial monitor to see the raw data coming from the sensor. You’ll be able to control the rate of an LED blinking using the input from a rotary angle sensor.

# What you’ll learn
* Stop a sketch that is running
* Set up a serial monitor
* Read analog input data from a sensor
* Use the analog input to control a digital output

## Gather your materials

* [UP2* board](http://www.up-board.org/upsquared)
* [Grove Pi+ board](http://wiki.seeedstudio.com/wiki/GrovePi%2b)
* [Grove* Rotary Angle Sensor](http://wiki.seeed.cc/Grove-Rotary_Angle_Sensor)
* [Grove* LED](http://wiki.seeed.cc/Grove-LED_Socket_Kit)

## Stop running sketches
This tutorial assumes you have already set up your board to work with Arduino Create*. If you haven’t done that, go back to the section on[Getting Started](https://software.intel.com/node/e5977984-ca1e-4e58-bbda-76292a51249d).

1. Make sure to stop any running sketches before proceeding with this tutorial. The hardware abstractions layer (MRAA*) locks the hardware pins it is using, so if you try to run a different sketch using those same pins while the previous sketch is still running, it won’t work.

2. To stop running sketches, go to the My Devices page by clicking the menu icon in the upper left and clicking "My Devices". Alternatively, you can go to [https://create-intel.arduino.cc/devices](https://create-intel.arduino.cc/devices).

3. Click "1 SKETCHES RUNNING" 
<img>

4. You should now see the name of the sketch that you ran to blink the LED, for example ‘Blink_mod’. Click "RUNNING".
<img>

5. You should now see "STOPPED".
<img>

## Connect hardware
1. Plug in the Grove LED to "D4" on the Grove Pi+ board.
<img>
2. Plug the Grove Rotary Angle Sensor into "A0".
<img>

## Get the code
1. In the Arduino Create Web Editor, open the "AnalogInput" example `Examples > 03.ANALOG > AnalogInput` and modify it as follows:
* Change `sensorPin` to `512`.
* Change `ledPin` to `516`.
* At the top of the setup() method, insert this line to add the subplatform:
`mraa_add_subplatform(MRAA_GROVEPI, "0");`
* Add `DebugSerial.begin(115200);` to the end of the setup() function.

<p>Add <code>DebugSerial.println(sensorValue);</code> above the digitalWrite() line in the loop() function.</p>
</li>
</ol><br/><span style="font-weight: bold;">Note</span>: The rotary angle sensor, also known as a potentiometer, is an analog sensor.<br/><br/>
The code should look like this:
<pre>
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
  // stop the program for &lt;sensorvalue&gt; milliseconds:
  delay(sensorValue);
  // print sensor value to the serial monitor
  DebugSerial.println(sensorValue);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for for &lt;sensorvalue&gt; milliseconds:
  delay(sensorValue);
}</pre></li>
<li>Before you upload the example sketch to your board, make sure to open the <span style="font-weight: bold;">Monitor</span> in Arduino Create.  This example outputs the raw analog data values out to the serial monitor.<br/><img src="/sites/default/files/did_feeds_images/783cf14f-4e48-45f4-b3d6-21dc3aff16fb/783cf14f-4e48-45f4-b3d6-21dc3aff16fb-imageId=e5b6aa4f-2df6-4d7b-b26a-58bc2b8ffad0.png" alt="" style="border:none; width:100%; max-width:456px;" border="0"/><br/></li>
<li>Upload the example sketch by clicking the <span style="font-weight: bold;">Upload</span> icon in the upper right of the editor. You should see the LED blink. If you turn the knob on the rotary angle sensor, you can change the rate of the blinking.<br/><br/>
If this isn’t working, double-check that you have stopped any other running sketches on the My Devices page (<a href="https://create-intel.arduino.cc/devices" target="_blank">https://create-intel.arduino.cc/devices</a>). Once there, if you see an “N Sketches Running” message, click <span style="font-weight: bold;">Running</span> and <span style="font-weight: bold;">Stop</span> any sketches. If you’ve tried stopping your sketch, but it still doesn’t work, try restarting your UP² board.</li>
</ol><h2>How it works</h2>
<p>You’ll notice that in the code, 512 corresponds to A0 on the Grove Pi+* board, while 516 corresponds to D4.  The code doesn’t use 0 or 4 to because you’re required to add an offset of 512 to any pin on the Grove Pi+ board.</p>
<p>Why? Under the covers, MRAA (the hardware abstraction library in Arduino) is using the Grove Pi+ board as a sub-platform!  So this line to add MRAA_GROVEPI as the sub-platform is required.</p>
<p><code>mraa_add_subplatform(MRAA_GROVEPI, "0");</code></p>
<p>Whenever you use a sub-platform in MRAA, you need to add an offset of 512 to whatever pin you are using.  For example, if you’re setting the pin mode of a GPIO pin 4, normally your code would look like this:</p>
<p><code>pinMode(4, OUTPUT);</code></p>
<p>but with a sub-platform, your code would look like this:</p>
<p><code>pinMode(516, OUTPUT);</code></p>
<p>Digital pins and analog pins both start at zero. Therefore, Analog pin 0 (A0) corresponds to 512, and Digital pin 4 (D4) corresponds to 516.</p>
<p>If you’re still unclear how this works, go back to the Blink LED example and read <a href="/node/d363382b-de12-4019-9c10-c9c89470dd74#Understanding_how_the_code_works">this section about MRAA and sub-platforms</a>.</p>
<p>The serial monitor is started in the setup() function.</p>
<p><code>DebugSerial.begin(115200);</code></p>
<p>Data can then be sent using:</p>
<p><code>DebugSerial.println(sensorValue);</code></p>
<p>For more detailed information on how to use the serial monitor, see the <a href="/node/8d850e2a-d72f-4652-bcbd-254335682b5f">Serial Monitor</a> tutorial.</p>
</div>
