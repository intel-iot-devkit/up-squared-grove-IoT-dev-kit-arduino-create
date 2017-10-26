# People Counter in C++/OpenCV for Arduino Create IDE 

## Introduction

## What you’ll learn
In this tutorial, you’ll learn how to:
  1.	[Setup OpenCV 3.3.0 on Ubuntu 16.04 LTS](readme.md#setup-opencv)
  2.	Build a people counter application from source code in Arduino Create IDE
  3.	Run the people counter application from the command prompt on your Ubuntu desktop

## Gather your materials
You’ll need the following to complete this tutorial:
  *	[UP Squared board](http://www.up-board.org/upsquared/)
  *	Ubuntu 16.04
  * OpenCV version 3.3.0
  *	A UVC webcam

[Click here for instructions on how to set up the OpenCV libraries on your hardware.](https://github.com/intel-iot-devkit/up-squared-grove-IoT-dev-kit-arduino-create/blob/master/examples/OpenCV-Setup/README.md)

## Setup OpenCV

This sections contains the instructions to download, compile and install the OpenCV 3.3.0 libraries on the Ubuntu desktop.

### Download
Open a command prompt and type:

```
cd ~
mkdir opencv
cd opencv
wget -O opencv-3.3.0.zip https://github.com/Itseez/opencv/archive/3.3.0.zip
wget -O opencv_contrib-3.3.0.zip https://github.com/Itseez/opencv_contrib/archive/3.3.0.zip
```
[//]: # ()

Unzip the downloaded archive:

```
unzip opencv-3.3.0.zip
unzip opencv_contrib-3.3.0.zip
```
[//]: # ()


### Compile
To build (or compile) the OpenCV libraries, navigate to the folder *opencv-3.3.0* and create a *build* directory:

```
cd opencv-3.3.0
mkdir build
cd build
```
In the `~/opencv/opencv-3.3.0/build ` directory, create the make files:

```
cmake ../
make
```
Approximate compile time: 55m 56s

*Specifying the number of threads/cores to utilize*
Approximate compile time:
```
make -j3
```

**Note**: The `cmake` and `make` commands must complete successfully for you to continue with the installation below.

### Install
From the  `~/opencv/opencv-3.3.0/build ` directory, type:
```
sudo make install
sudo ldconfig
```

`ldconfig` tells the operating system that the OpenCV libraries are available. `sudo` is used to...

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
