# People Counter in C++/OpenCV for Arduino Create IDE 

## Introduction

## What you’ll learn
In this tutorial, you’ll learn how to build and run a people counting computer vision application from source code in the Arduino Create IDE. The application will be executed from the command prompt.

## Gather your materials
You’ll need the following to complete this tutorial:
  *	[UP Squared board](http://www.up-board.org/upsquared/) (tested hardware)
  *	Ubuntu 16.04
  * OpenCV version 3.3.0
  *	A UVC webcam

[Click here for instructions on how to set up the OpenCV libraries on your hardware.](https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/blob/master/examples/OpenCV-Setup/README.md)

## Get the Code

People Counter Code Sample

```
#include "ArduinoOpenCV.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/video.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void drawText(Mat & image);
```

## Arduino Create IDE

Copy and paste the code above into the Arduino Create IDE. Open a session in the Arduino Create IDE, begin a NEW SKETCH and paste the code into the sketch window. 

### Verify
[//]: # (insert screenshot of "done verifying...")

### Upload

[//]: # (insert screenshot of "done uploading...")

### Run the Application

**Note**: make sure you've plugged in a UVC webcam before attempting to run the application

When uploading the code to the target hardware, the Arduino Create IDE will compile the code and create an executable. After successfully uploading the sketch to the target hardware, a *sketches* folder will be created in the Home directory. You will need be logged in as root to run the application from the folder (protected).

```
su
cd sketches
```
```
./people-detect
```

A window should pop up and when a person is detected, you'll see a green bounding box around the person. The counting feature... 

## How it works
Place commented code snippets here.
