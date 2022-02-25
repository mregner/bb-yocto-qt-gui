# bb-yocto-qt-gui

Package for building custom yocto images with QT on the Beaglebone.

## To build

Create a base build directory, eg `mkdir ~/yocto && cd ~/yocto`

Clone the build environment Docker package `https://github.com/mregner/yocto-builder.git` and this package

Build the yocto env from the builder package `docker build -t yocto-builder:latest yocto-builder/`

Start the docker build environment ``docker run  -it --rm -v `pwd`:/home/dev yocto-builder:latest``

Build the linux image: `./build_image_minimal`

