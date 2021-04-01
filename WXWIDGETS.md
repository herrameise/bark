# wxWidgets Build Guide

This document describes how to build the **wxWidgets 3.1.4** release on **Ubuntu 20.04 Desktop (64-bit)**.

## Dependencies

Install dependencies:
```
$ sudo apt-get update
$ sudo apt-get install libgtk-3-dev
```

## Build and Install

Download the wxWidgets 3.1.1 [source](https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.4/wxWidgets-3.1.4.tar.bz2) and extract:
```bash
$ bunzip2 wxWidgets-3.1.1.tar.bz2
$ tar xvf wxWidgets-3.1.1.tar
$ cd wxWidgets-3.1.1/
```

Create a dedicated build directory, descend into the build directory, and configure as follows:
```bash
wxWidgets-3.1.1/$ mkdir gtk3-build
wxWidgets-3.1.1/$ cd gtk3-build
wxWidgets-3.1.1/gtk3-build/$ ../configure --enable-debug --with-gtk=3
```

Make and install:
```bash
wxWidgets-3.1.1/gtk3-build/$ make -j$(nproc)
wxWidgets-3.1.1/gtk3-build/$ sudo make install
wxWidgets-3.1.1/gtk3-build/$ sudo ldconfig
```

## wxFormBuilder

**wxFormBuilder** is a WYSIWYG interface designer for wxWidgets. It is used to modify the `*.fbp` files in the repository, which can automatically generate C++ headers and source files to build the GUI elements. It comes as a [flatpak](https://flatpak.org/) package for Linux. **NOTE: You only need to install this if you intend on manipulating any of the user interfaces.** For building the source code as-is, this is not necessary.

Install dependencies:
```bash
$ sudo add-apt-repository ppa:alexlarsson/flatpak
$ sudo apt-get update
$ sudo apt-get install flatpak
```

Download the latest flatpak release from the [wxFormBuilder Github page](https://github.com/wxFormBuilder/wxFormBuilder) and install:
```bash
$ sudo flatpak install wxformbuilder.flatpak
```

After installation finishes, the application can be run from the command line (`flatpak run org.wxformbuilder.wxFormBuilder`) or via the Ubuntu launcher.
