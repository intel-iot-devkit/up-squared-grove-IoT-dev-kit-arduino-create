[//]: # (Joe Butler comment below)

[//]: # (Install Ubuntu desktop environment, Restart, Setup a monitor/keyboard/mouse)

[//]: # (Install opencv) 

[//]: # (Run test #1 -- to get version, Run test #2 -- display a video file) 

[//]: # (download a video, run the sketch, login to machine, change to root user, run it)

# How to Build and Install the OpenCV Libraries on Ubuntu
## Introduction
This tutorial contains the instructions to setup OpenCV 3.3.0 on the Ubuntu 16.04 LTS operating system.

## What you'll Learn
* Download, build (compile) and install the OpenCV 3.3.0 libraries

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
cmake -D CMAKE_BUILD_TYPE=RELEASE \-D INSTALL_PYTHON_EXAMPLES=OFF \-D INSTALL_C_EXAMPLES=ON \-D OPENCV_EXTRA_MODULES_PATH=~/opencv/opencv_contrib-3.3.0/modules \-D PYTHON_EXECUTABLE=python \-D BUILD_EXAMPLES=ON ..

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

### Hardware Setup: connect monitor, keyboard and mouse
Plug in a USB keyboard and mouse into the USB ports available on the UP2 hardware. 

Next, gather a HDMI or display port compatible monitor along with it's corresponding cable and connect the monitor to the board by plugging in the cable to the available ports on the UP2 hardware.

### Install Ubuntu desktop environment
The UP2 kit comes with the Ubuntu server operating system pre-installed on the UP2 board but does not include the Ubuntu desktop environment. You'll need to install the desktop environment in order to view the results of image or video streams processed by OpenCV\*.

[//]: # (sudo apt-get install --no-install-recommends ubuntu-desktop)
[//]: # (always use sudo with apt)

[//]: # (`--no-install-recommends` includes required dependencies only. You can see the full list at https://packages.ubuntu.com/xenial/ubuntu-desktop)

**Note**: if you are behind a firewall, configure your proxy before proceeding with the commands that follow.

```
suo apt update
sudo apt install ubuntu-desktop
```

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
apt update
apt install --no-install-recommends ubuntu-desktop
```

`--no-install-recommends` saves space on the drive by installing the minimum required components.

Reboot your system after the install completes:
```
reboot
```
#### MRAA (optional)
To add mraa, follow instructions at https://launchpad.net/~mraa/+archive/ubuntu/mraa

Once done, you should have all sources available and updated (including the ubuntu-desktop package).
