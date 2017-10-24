[//]: # (Joe Butler comment below)

[//]: # (Install Ubuntu desktop environment, Restart, Setup a monitor/keyboard/mouse)

[//]: # (Install opencv) 

[//]: # (Run test #1 -- to get version, Run test #2 -- display a video file) 

[//]: # (download a video, run the sketch, login to machine, change to root user, run it)

## Hardware Setup: connect monitor, keyboard and mouse
Plug in a USB keyboard and mouse into the USB ports available on the UP2 hardware. 

Next, gather a HDMI or display port compatible monitor along with it's corresponding cable and connect the monitor to the board by plugging in the cable to the available ports on the UP2 hardware.

## Install Ubuntu desktop environment
The UP2 kit comes with the Ubuntu server operating system pre-installed on the UP2 board but does not include the Ubuntu desktop environment. You'll need to install the desktop environment in order to view the results of image or video streams processed by OpenCV\*.

[//]: # (sudo apt-get install --no-install-recommends ubuntu-desktop)

[//]: # (`--no-install-recommends` includes required dependencies only. You can see the full list at https://packages.ubuntu.com/xenial/ubuntu-desktop)

Log in as root user:
```
sudo su
```
**Note**: if you are behind a firewall, configure your proxy before proceeding with the commands that follow.

```
apt update
apt install ubuntu-desktop
```

Reboot your system after the install completes.
```
reboot
```
### Other instructions (as needed)
May need to force if `apt update` outputs errors regarding lock.

Backup the current list using:
```
mv /etc/apt/sources.list /etc/apt/sources.list.old
```

Then download:

```
curl https://repogen.simplylinux.ch/txt/xenial/sources_806a0b140939fc6715a1303545ba86ee3f40492c.txt | sudo tee /etc/apt/sources.list
```

To add mraa, follow instructions at https://launchpad.net/~mraa/+archive/ubuntu/mraa

Once done, you should have all sources available and updated (including the ubuntu-desktop package).

Reboot your system after the install completes.
```
reboot
```

# OpenCV Setup

This sections contains the instructions to download, compile and install the OpenCV 3.3.0 libraries on the Ubuntu desktop.

## Download
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


## Compile
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

To achieve a faster compilation time, you can take advantage of the number of usable cores, `nproc`, in your CPU with either of the following modified `make` commands:

```
make -j $(nproc)
	-or-
make -j $(($(nproc)+1))
  ```
Approximate compile time:

**Note**: The `cmake` and `make` commands must complete successfully for you to continue with the installation below.

## Install
From the  `~/opencv/opencv-3.3.0/build ` directory, type:
```
sudo make install
sudo ldconfig
```

`ldconfig` tells the operating system that the OpenCV libraries are available. `sudo` is used to...
