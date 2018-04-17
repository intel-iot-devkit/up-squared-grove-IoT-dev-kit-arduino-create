# MQTT Publication with Microsoft Azure\*
<table>
	<tr>
		<td>Programming language</td>
		<td>C++ (Arduino*)</td>
	</tr>
	<tr>
		<td>Skill level</td>
		<td>Intermediate</td>
	</tr>
	<tr>
		<td>Time to complete</td>
		<td>5 minutes</td>
	</tr>
	<tr>
		<td>Hardware needed</td>
		<td>UP Squared* Grove* IoT Development Kit</td>
	</tr>
	<tr>
		<td>Target Operating System</td>
		<td>Ubuntu 16.04</td>
	</tr>
</table>

This tutorial takes you from setting up a device in Microsoft Azure\* all the way to viewing your data (sent via MQTT).  The sketch is setup to read data from the Grove\* Rotary Angle Sensor (at a given interval) and send it to the Microsoft Azure\* cloud platform.  The final step where you view your data is done in the Device Explorer\* tool provided by Microsoft\*.  It is only supported on Windows\* , see https://github.com/Azure/iothub-explorer for instructions on how to use the iot-hubexplorer node.js command line tool for other platforms.

## What you'll learn
* How to set up an IoT Hub
* How to get the credentials for your device and enter them into the "Secrets" tab in Arduino Create\*
* How to view your data using the Device Explorer tool

## Gather your materials
* [UP Squared\* board](http://www.up-board.org/upsquared/) 
* GrovePi+\* board
* Grove\* Rotary Angle sensor

### Software dependencies
* libcrypto
* libssl  

These will already be installed if you are using the OS that was shipped with the UP Squared\* Grove\* IoT Development Kit. Otherwise you need to install them via apt-get. 

apt-get install libssl-dev

## Plug in your sensor
Connect the Grove Rotary Angle Sensor to pin **A0** on the Grove Pi+

## Create an account
If you don't have a Microsoft Azure account, sign up for a free trial https://azure.microsoft.com/en-us/free/ 

## Create an IoT Hub
You need an IoT Hub to enable communication between Microsoft Azure and your device. The easiest way to create an IoT Hub is through the Microsoft Azure portal. Follow the steps in https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal.

The portal is located at https://portal.azure.com

1. Click "New" and search for "iot"

![](./../../extras/screen1.png)

2. Name your hub something unique, for example my-iot-hub###, where ### is some number. It is recommended to use the default settings for the IoT hub creation.

![](./../../extras/screen2.png)

When it's done being created you should see it appear in the Dashboard.

![](./../../extras/screen3.png)


## Create a shared access policy

1. Open your hub and select **Shared access policies**, under **SETTINGS**.

![](./../../extras/screen4.png)

2. Click **Add**.

![](./../../extras/screen5.png)

3. Select read, service connect, and device connect permissions.  Give it a name such as "my-policy".

![](./../../extras/screen6.png)

4. The policy you created should now show up under **POLICY**. 

![](./../../extras/screen7.png)

5. Click on your policy and copy the **Connection string - primary key** (also known as the Hub connection string). You will need it later.

![](./../../extras/screen8.png)

## Setup device explorer

View your data using either the Device Explorer tool or the iot-hubexplorer node.js command line tool (supported on Windows, macOS\, and Linux\*).

This tutorial will you walk you through using the Device Explorer GUI on Windows.  See https://github.com/Azure/iothub-explorer for instructions on how to use the iot-hubexplorer node.js command line tool. 

1. Download and install the **SetupDeviceExplorer.msi** from https://github.com/Azure/azure-iot-sdk-csharp/releases.

2. Enter the **Connection string - primary key** you copied from step #5 of the above section into the **IoT Hub Connection String** field in the Configuration tab of the application.  Then click **Update**.  You should see a popup confirming that it was successful.

![](./../../extras/screen9.png)

5. Go to the **Management** tab.
![](./../../extras/screen10.png)

6. Click **Create** and enter a Device ID, for example "test-device".  The Primary and Secondary keys should have populated automatically.

![](./../../extras/screen11.png)

7. Right click on the device you just created, and select **Copy connection string for selected device**

![](./../../extras/screen12.png)


## Get the code

1. Open the example **Libraries>AZURE IOT DEVICE SDK>Examples>ClientMqtt**

![](./../../extras/screen13.png)

2. Copy the connection string from step #7 above into the Secret tab of the sketch.

![](./../../extras/screen14.png)

3. Build and Upload the sketch.

## View the data
Go to the **Data** tab and click **Monitor**.  You should see a message saying "Receiving events" or similar.  This is where you will see messages once your application is running on your target.

![](./../../extras/screen15.png)

