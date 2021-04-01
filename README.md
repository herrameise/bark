# BARK

BARK - the **B**inary **AR**my **K**nife. A tool for visualizing and editing binary files. A "blade" is a plugin for BARK.

![BARK screenshot](/img/screenshot.png)

**NOTE**: This software is in very "pre-alpha" status and still has a lot of bugs. There is also a (private) refactor effort to use [Qt](https://www.qt.io/) instead, so there will likely be no more updates to this code base.

## Building

These instruction assume **Ubuntu 20.04 Desktop (64-bit)**, but the build process should be similar for other version of Ubuntu or other Linux distributions.

First, [build and install wxWidgets](WXWIDGETS.md) from source. 

Install dependencies for `BARK`:
```bash
$ sudo apt-get update
$ sudo apt-get install libboost-all-dev
```

Make and install the `BARK` core library and desktop application. The output files will be in the local `bin/` directory. It would be wise to multi-thread the `make` command (something like `make -j8`) since there are quite a few source files to compile.
```bash
$ make -j$(nproc)
$ sudo make install
$ sudo ldconfig
```

Run the desktop applicaiton:
```bash
$ cd bin/
bin/$ ./barkapp
```

If you get the following error, you likely skipped the `make install` command above (the BARK core library was not installed to `/usr/local/lib`).
```bash
bin/$ ./barkapp
./barkapp: error while loading shared libraries: libbark.so: cannot open shared object file: No such file or directory
```

## Usage

First, load a file (specimen) into the analysis engine with `File --> Load Specimen`. Then deploy a few blade instances with `Blades --> Deploy...`.

The `Editor` blade is a hex editor that can display in hexadecimal or binary (as well as ASCII) and has a right-click context menu to insert/delete bytes, apply an XOR mask, delete selections, and other byte-level operations. Open up several instances of the `Editor` and see how the selection propagates automatically to every deployment in real-time. Drag the bottom-right corner of the `Editor` window to dynamically change the amount of data elements displayed per line.

The `Visualizer` blade is much more experimental. It creates a raster plot of the bits in the specimen with user-specified separators and color schemes.

## Where did the name come from?

It is a play on [QuArK](https://en.wikipedia.org/wiki/Quake_Army_Knife) (the "Quake Army Knife"), a 3D level editor for the Quake series of computer games.
