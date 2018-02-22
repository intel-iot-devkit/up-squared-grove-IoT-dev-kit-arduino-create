# MQTT Publication with Amazon Web Services (AWS)\*
<table>
	<tr>
		<td>Programming language</td>
		<td>C++ (Arduino)</td>
	</tr>
	<tr>
		<td>Skill level</td>
		<td>Intermediate</td>
	</tr>
	<tr>
		<td>Time to complete</td>
		<td>15 minutes</td>
	</tr>
	<tr>
		<td>Hardware needed</td>
		<td>UP Squared Grove IoT Development Kit</td>
	</tr>
	<tr>
		<td>Target Operating System</td>
		<td>Ubuntu 16.04</td>
	</tr>
</table>

This tutorial shows you how to go from setting up an account with AWS\* to sending data via MQTT.  It uses the aws-iot-device-sdk-cpp.h library from https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create , which is a slightly modified version of the AWS\* IoT Device SDK https://github.com/aws/aws-iot-device-sdk-cpp.  

## What you'll learn
* How to setup an AWS account and Thing
* How to create a certificate for your Thing
* How to enter the certificate in the SECRETS tab 
* How to verify the connection in AWS

## Gather your materials
* [UP² board](http://www.up-board.org/upsquared/) 

### Software dependencies
* libcrypto
* libssl  
These will already be installed if you are using the OS that was shipped with the UP Squared Grove IoT Development Kit.  Otherwise you need to install them via apt-get.

## Set up AWS portal

1.  Go to AWS IOT console and register or sign in.

    <https://aws.amazon.com/console/>

2.  Search for IOT Services and find ‘AWS IoT’
    
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step1.png)
    

3.  Click get Started
    
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step2.png)
    
4.  Click on Registry &gt; Things &gt; Register a
    Thing
    
    
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step3.png)

    

5.  Enter a thing name e.g. ‘Thing-01’ and click ‘Create Thing’

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step4.png)
    
6.  The thing is now created. Click on it to see its details.

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step4Result.PNG)

7.  Click on ‘Interact’ and copy the HTTPS endpoint value. This value
    will be used in the sample.

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step11.png)
    
8.  Click the back arrow to get back to the main page and click on
    ‘Security’ &gt; ‘Policies’ . Then click ‘Create a Policy’

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step8.png)

9.  Give a Name e.g. ‘Policy-01’. Add a statement with Action ‘iot:\*’, Resource ARN ‘\*’ and Effect ‘Allow’. Click on ‘CREATE’.

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step9.png)

10. Go to ‘Security’ \> ‘Certificates’ and click on ‘Create Certificate’ 

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step5.png)

11. Click ‘Create Certificate’ again

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step6.png)

12. Download the four files and click ‘Activate’. Then click ‘Attach a Policy’

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step7.png)

13. Select the policy created in the previous steps. Click ‘Done’.

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Step10.png)

   
## Get the code

1.  Open the PubSub example in Arduino Create\* **Examples>FROM LIBRARYES>UP SQUARED GROVE IOT DEV KIT>MqttPubAWS**

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/SampleStep0.png)

2.  Enter the endpoint value, the thing name and the client ID in the
    sample file’s \#define. The client ID and thing name are same.
    Update the sample pub-sub topic if you want.

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/SampleStep1.png)

3.  Switch to the SECRET tab. Open the files downloaded as text file and
    copy the string to the entries in the secret tab.

    SECRET\_ROOT\_CA : Content of file “VeriSign-Class
    3-Public-Primary-Certification-Authority-G5.pem”

    SECRET\_CLIENT\_CERT : Content of file ending in
    \*-certificate.pem.crt

    SECRET\_CLIENT\_PRIVATE\_KEY : Content of file ending in
    \*-private.pem.key.
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/SampleStep2.png)
    Click ‘Save’ and Verify and upload the sample to device.

    Note : To be more secure, it is recommended that the root
    certificate, cient certificate and client private key be put on the
    device directly and read from there by the sample. To do that,
    transfer these files to your device, make note of the absolute file
    name and provide that in the values in the secret path. In the
    DEFAULTSAMPLECONFIG value, set ‘load\_crts\_as\_string’ to false.
    This will load the certificates from those file paths instead of as
    strings.

### Monitor the topic in AWS\* IoT dashboard

1.  Go to the Dashboard (you can navigate to it in the left menu from the console https://aws.amazon.com/console/). A graphical representation of device connections and messages can be seen.  You should see a connection corresponding to the time you ran the sketch.
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/Dashboard.png)

2.  The sample’s published messages can be tested by received by
    subscribing to the topic through the Test widget.  Navigate to the Test widget from the console https://aws.amazon.com/console/.

    Enter the name of the thing that was created
    earlier e.g. ‘thing-01’. Client ID and thing name are same. Click
    ‘Connect’.
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/MonitorStep1.png)
    
    Enter the topic that the sample is configured to. This is the value
    of SDK\_SAMPLE\_TOPIC in the program, which is 'sdk/test/cpp' in this case. Click ‘Subscribe to Topic’
    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/MonitorStep2.png)
    
    When the sample runs, you will see the published messages, like below:

    ![](https://github.com/intel-iot-devkit/aws-iot-device-sdk-cpp-arduino-create/blob/master/extras/MonitorStep3.png)


