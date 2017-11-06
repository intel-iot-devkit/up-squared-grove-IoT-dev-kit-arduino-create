
# OpenCV Setup
OpenCV is the main library used for computer vision and image processing.  For sketches created in Arduino Create, the OpenCV library is dynamically linked, which means it must be installed on the target platform first in order to run. This tutorial contains the instructions to setup OpenCV 3.3.0 on the Ubuntu\* Server 16.04 LTS operating system that comes with the UPSquared\* Grove IoT Development Kit, though they can generally be applied to any Intel®-based system.

## What you'll Learn
* How to Download, build (compile) and install the OpenCV 3.3.0 libraries from the command line
* Install the Ubuntu\* desktop on a Ubuntu Server 16.04 OS
* Verify your OpenCV installation in Arduino Create\*

## Gather Your Materials
* UPSquared Board or other Intel® processor-based hardware with Ubuntu 16.04 LTS

## Download

**Note**: if you are behind a firewall, configure your proxy before proceeding with the commands that follow.

Open a command prompt and type:

```
cd ~
mkdir opencv
cd opencv
wget -O opencv-3.3.0.zip https://github.com/opencv/opencv/archive/3.3.0.zip
wget -O opencv_contrib-3.3.0.zip https://github.com/opencv/opencv_contrib/archive/3.3.0.zip
```
[//]: # ()

Unzip the downloaded archive:

```
unzip opencv-3.3.0.zip
unzip opencv_contrib-3.3.0.zip
```

## Compile
To build (or compile) the OpenCV libraries, navigate to the folder *opencv-3.3.0* and create a *build* directory:

```
cd opencv-3.3.0
mkdir build
cd build
```
In the `~/opencv/opencv-3.3.0/build ` directory, create the make files:

[//]: # (cmake ../)
```
cmake -D CMAKE_INSTALL_PREFIX=/usr/local -D CMAKE_BUILD_TYPE=RELEASE \-D INSTALL_PYTHON_EXAMPLES=OFF \-D INSTALL_C_EXAMPLES=ON \-D OPENCV_EXTRA_MODULES_PATH=~/opencv/opencv_contrib-3.3.0/modules \-D PYTHON_EXECUTABLE=python \-D BUILD_EXAMPLES=ON ..

make -j $3
```
Approximate compile time: varies depending on the number of usable cores in the processor

To achieve an optimal compilation time, we can take advantage of the number of usable cores, `nproc`, in the CPU by appending the make command with `-j $(nproc)`. If the hardware you are using supports hyperthreading, you may also try appending the `make` command with either `-j $(($(nproc)+1))` or `-j $(($(nproc)+$(($(nproc)/2))))`.

**Note**: The `cmake` and `make` commands must complete successfully for you to continue with the installation below.

## Install
From the  `~/opencv/opencv-3.3.0/build ` directory, type:
```
sudo make install
sudo ldconfig
```

`ldconfig` tells the operating system that the OpenCV libraries are available.

## Install desktop environment (required for UPSquared\* Grove\* IoT Development Kit)

### Hardware Setup
In this step, you will a connect monitor, keyboard and mouse to the UP² board.

1. Plug in a USB keyboard and mouse into the USB ports available on the UP² hardware. 

2. Next, gather a HDMI or display port compatible monitor along with it's corresponding cable and connect the monitor to the board by plugging in the cable to the available ports on the UP² hardware.

3. Ensure that you are connected to the Internet by plugging in an Ethernet cable to the Ethernet port on the UP² board.

### Install Ubuntu\* desktop environment
The UP² kit comes with the Ubuntu server operating system pre-installed on the UP² board but does not include the Ubuntu desktop environment. You'll need to install the desktop environment in order to view the results of image or video streams processed by OpenCV.

**Note**: if you are behind a firewall, configure your proxy before proceeding with the commands that follow.

```
sudo apt update
sudo apt-get install --no-install-recommends ubuntu-desktop
```
**Note**: The use of `--no-install-recommends` includes required dependencies only. You can see the full list at https://packages.ubuntu.com/xenial/ubuntu-desktop

Reboot your system after the install completes.
```
reboot
```

You will find that the desktop environment is quite bare.  To install some optional applications get to the command prompt by pressing **CTRL** + **ALT** + **F1** , here's a few useful ones
```
sudo apt-get install gnome-terminal
sudo apt-get install firefox
sudo apt-get install gedit
```

To get back to your desktop enter **CTRL** + **ALT** + **F7** 

## Validate OpenCV Setup on UPSquared\* using Arduino Create\*
The steps that follow are intended to verify that Arduino Create, UPSquared hardware and OpenCV work together successfully to run a basic example application.  

**Note:  The general process below should be followed for running all OpenCV applications in Arduino Create. A sketch ran from Arduino Create cannot access your desktop to display the video, so it first needs to be uploaded with Arduino Create, and then ran manually from your UP Squared board.**  

1. In the Arduino Create Web Editor, open the **Contours** example **EXAMPLES>FROM LIBRARIES>UP SQUARED GROVE IOT DEVELOPMENT KIT>OpenCV-Setup**
2. Verify and then upload the sketch.  
3. Run the sketch from the Ubuntu desktop environment on the UP² hardware: 

```
sudo su
cd sketches
```
```
./Contours
```
Two windows should pop up. One that you can interact with (move a slide bar) and another to show the results of moving the slide bar.

Congratulations! Your OpenCV Setup is now working.
