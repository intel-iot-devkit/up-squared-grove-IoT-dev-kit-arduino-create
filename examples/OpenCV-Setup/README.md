[//]: # (Joe Butler comment below)

[//]: # (Install GUI, Restart, Setup a monitor/keyboard/mouse)

[//]: # (Install opencv) 

[//]: # (Run test #1 -- to get version, Run test #2 -- display a video file) 

[//]: # (download a video, run the sketch, login to machine, change to root user, run it)

## Install a GUI
Because the Ubuntu 16.04 operating system (included with the UP2 kit) does not have a Graphical User Interface (GUI), you'll need to install a GUI in order to view the results of image or video streams processed by OpenCV\*.

```
sudo apt-get install --no-install-recommends ubuntu-desktop
```
`--no-install-recommends` includes required dependencies only. You can see the full list at https://packages.ubuntu.com/xenial/ubuntu-desktop 

Reboot your system to complete the GUI install
```
reboot
```

### Set up a monitor, keyboard, and mouse
<add>

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

To achieve a faster compilation time, you can take advantage of the number of usable cores (`nproc`) in your CPU with either the following modified `make` commands:

```
make -j $(nproc)
	-or-
make -j $(($(nproc)+1))
  ```
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
