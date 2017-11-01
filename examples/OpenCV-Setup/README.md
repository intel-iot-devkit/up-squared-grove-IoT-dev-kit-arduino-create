
# How to Build and Install the OpenCV Libraries on Ubuntu
## Introduction
This tutorial contains the instructions to setup OpenCV 3.3.0 on the Ubuntu 16.04 LTS operating system. Instructions for UP2 users to install the Ubuntu desktop environment along with steps to verify that OpenCV has been installed correctly can be found in the second half of this tutorial.

## What you'll Learn
* How to Download, build (compile) and install the OpenCV 3.3.0 libraries from the command line

## Gather Your Materials
* UP Squared Board (tested) or other Intel® processor-based hardware
* Ubuntu 16.04 LTS

# OpenCV Setup

## Download

**Note**: if you are behind a firewall, configure your proxy before proceeding with the commands that follow.

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

make -j $(nproc)
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

# UP2 Users
## Before you setup OpenCV 
Before you build and install the OpenCV libraries, setup your UP2 hardware and install the Ubuntu desktop environment.

### Hardware Setup
In this step, you will a connect monitor, keyboard and mouse to the UP2 board.

1. Plug in a USB keyboard and mouse into the USB ports available on the UP2 hardware. 

2. Next, gather a HDMI or display port compatible monitor along with it's corresponding cable and connect the monitor to the board by plugging in the cable to the available ports on the UP2 hardware.

3. Ensure that you are connected to the Internet by plugging in an Ethernet cable to the Ethernet port on the UP2 board.

### Install Ubuntu desktop environment
The UP2 kit comes with the Ubuntu server operating system pre-installed on the UP2 board but does not include the Ubuntu desktop environment. You'll need to install the desktop environment in order to view the results of image or video streams processed by OpenCV\*.

**Note**: if you are behind a firewall, configure your proxy before proceeding with the commands that follow.

```
suo apt update
sudo apt-get install --no-install-recommends ubuntu-desktop
```
**Note**: The use of `--no-install-recommends` includes required dependencies only. You can see the full list at https://packages.ubuntu.com/xenial/ubuntu-desktop

Reboot your system after the install completes.
```
reboot
```
### Other instructions (troubleshooting as needed)
May need to force if `apt update` outputs errors regarding lock.

Backup the current list using:
```
mv /etc/apt/sources.list /etc/apt/sources.list.old
```

Then download:

```
curl https://repogen.simplylinux.ch/txt/xenial/sources_806a0b140939fc6715a1303545ba86ee3f40492c.txt | sudo tee /etc/apt/sources.list
```
To force:
```
sudo rm /var/lib/apt/lists/lock 
```

Run the update and install commands:
```
sudo apt update
sudo apt install --no-install-recommends ubuntu-desktop
```

`--no-install-recommends` saves space on the drive by installing the minimum required components.

Reboot your system after the install completes:
```
reboot
```

## Validate OpenCV Setup on UP2 using the Arduino Create IDE
The steps that follow are intended to verify that Arduino Create IDE, UP2 hardware and OpenCV work together successfully to run a basic example application.

1. In the Arduino Create Web Editor, navigate to the **FROM LIBRARIES TAB** and find the "Contours" example in the **OPENCV** directory.
2. Verify and then upload the sketch.
3. To run the sketch from the Ubuntu desktop environment on the UP2 hardware: 

```
sudo su
cd sketches
```
```
./Contours
```
Two windows should pop up. One that you can interact with (move a slide bar) and another to show the results of moving the slide bar.
