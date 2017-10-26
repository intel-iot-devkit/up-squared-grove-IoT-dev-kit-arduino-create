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

static void detectAndDraw(const HOGDescriptor &hog, Mat &img)
{
    vector<Rect> found, found_filtered;
    double t = (double) getTickCount();
    // Run the detector with default parameters. to get a higher hit-rate
    // (and more false alarms, respectively), decrease the hitThreshold and
    // groupThreshold (set groupThreshold to 0 to turn off the grouping completely).
    hog.detectMultiScale(img, found, 0, Size(8,8), Size(16,16), 1.07, 2);
    t = (double) getTickCount() - t;
    cout << "detection time = " << (t*1000./cv::getTickFrequency()) << " ms" << endl;
    for(size_t i = 0; i < found.size(); i++ )
    {
        Rect r = found[i];
        size_t j;
        // Do not add small detections inside a bigger detection.
        for ( j = 0; j < found.size(); j++ )
            if ( j != i && (r & found[j]) == r )
                break;
        if ( j == found.size() )
            found_filtered.push_back(r);
    }
    for (size_t i = 0; i < found_filtered.size(); i++)
    {
        Rect r = found_filtered[i];
        // The HOG detector returns slightly larger rectangles than the real objects,
        // so we slightly shrink the rectangles to get a nicer output.
        r.x += cvRound(r.width*0.1);
        r.width = cvRound(r.width*0.8);
        r.y += cvRound(r.height*0.07);
        r.height = cvRound(r.height*0.8);
        rectangle(img, r.tl(), r.br(), cv::Scalar(0,255,0), 3);
    }
}


void setup()
{
    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    cout << "Built with OpenCV " << CV_VERSION << endl;
    Mat image;
    VideoCapture capture;
    capture.open(0);
    if(capture.isOpened())
    {
        cout << "Capture is opened" << endl;
        for(;;)
        {
            capture >> image;
            if(image.empty())
                break;
            drawText(image);
            detectAndDraw(hog, image);
            imshow("people detector", image);
            //imshow("Sample", image);
            if(waitKey(10) >= 0)
                break;
        }
    }
    else
    {
        cout << "No capture" << endl;
        image = Mat::zeros(480, 640, CV_8UC1);
        drawText(image);
        imshow("Sample", image);
        waitKey(0);
    }
}

void loop() {}

void drawText(Mat & image)
{
    putText(image, "Hello OpenCV",
            Point(20, 50),
            FONT_HERSHEY_COMPLEX, 1, // font face and scale
            Scalar(255, 255, 255), // white
            1, LINE_AA); // line thickness and type
}

```

## Arduino Create IDE

Open a session in the Arduino Create IDE, begin a NEW SKETCH and paste the code into the sketch window. Save your sketch and name it as people_detect_count.

![Arduino Create IDE](capture-1.PNG)

### Verify
[//]: # (insert screenshot of "done verifying...")

![done verifying](verify.PNG)

### Upload

[//]: # (insert screenshot of "done uploading...")

![done uploading](upload.PNG)

### Run the Application

**Note**: make sure you've plugged in a UVC webcam before attempting to run the application

After successfully uploading the sketch to the target hardware, a *sketches* folder will be created in the *Home* directory on the Ubuntu desktop (where the Arduino Create IDE places an executable). Because the sketches folder is protected, You'll need to run the application as root user.

```
sudo su
cd sketches
```
```
./people_detect_count
```

A window should pop up and when a person is detected, you'll see a green bounding box around the person.

## How it works
Place commented code snippets here.
