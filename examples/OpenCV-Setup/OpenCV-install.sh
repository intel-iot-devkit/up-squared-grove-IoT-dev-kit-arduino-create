cd ~/Downloads
mkdir opencv
cd opencv
wget -O opencv-3.3.0.zip https://github.com/opencv/opencv/archive/3.3.0.zip
wget -O opencv_contrib-3.3.0.zip https://github.com/opencv/opencv_contrib/archive/3.3.0.zip
sudo apt-get install unzip
unzip opencv-3.3.0.zip
unzip opencv_contrib-3.3.0.zip
sudo apt-get install libgtk2.0-dev
sudo apt-get install pkg-config
cd ~/Downloads/opencv/opencv-3.3.0
mkdir build && cd build
cmake -D CMAKE_INSTALL_PREFIX=/usr/local -D CMAKE_BUILD_TYPE=RELEASE \-D INSTALL_PYTHON_EXAMPLES=OFF \-D INSTALL_C_EXAMPLES=ON \-D OPENCV_EXTRA_MODULES_PATH=~/opencv/opencv_contrib-3.3.0/modules \-D PYTHON_EXECUTABLE=python \-D BUILD_EXAMPLES=ON ..
make -j3
sudo make install
sudo ldconfig