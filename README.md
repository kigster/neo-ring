          
> **NOTE**: This project has been auto-generated using:
> 
>  * [arli](https://github.com/kigster/arli) Arduino toolkit, and using the `generate` command. Thank you for using Arli!
>  * [arli-cmake](https://github.com/kigster/arli-cmake) is the template project that was used as a source for this one.
>  * [arduino-cmake](https://github.com/arduino-cmake/arduino-cmake) is the CMake-based build system for Arduino projects.
>
> There is a discussion board for Arli/CMake-based projects. Please join if you have any questions or suggestions!
> [![Gitter](https://img.shields.io/gitter/room/gitterHQ/gitter.svg)](https://gitter.im/arduino-cmake-arli/)


# NeoRing

NeoPixel Ring with multiple effects for a little cube.

## Prerequisites

 * On a Mac, you always need to run `xcode-select --install` before you can do any development. You must have `git` installed;

 * Requires [CMake](https://cmake.org/download/)

 * Requires [Arduino IDE](https://www.arduino.cc/en/Main/Software) or an SDK, either for [Mac](https://downloads.arduino.cc/arduino-1.8.5-macosx.zip) or [Linux](https://downloads.arduino.cc/arduino-1.8.5-linux.zip) installed;

 * Requires ruby, 2.3 or 2.4+ installed. On a Mac's Terminal, run `ruby --version`. If for some reason you don't have it installed, the `bin/setup` script will prompt you to install it.

## Building NeoRing
 
```bash
$ cd ~/workspace/NeoRing
$ rm -rf build && mkdir -p build && cd build
$ cmake ..
$ make                          # this builds the image
$ make upload                   # this uploads it to the device
$ # this next command opens a serial port monitor inside a screen session
$ make NeoRing-serial   
```

### Customizing the Build

You can use environment variables to set the board, CPU and the port. Simply prefix the following variables before you run `cmake ..`

```bash
$ rm -rf build
$ mkdir -p build
$ cd build
$ BOARD_NAME=nano \
  BOARD_CPU=atmega328p \
  BOARD_DEVICE=/dev/tty.usbserial-DA00WXFY \
  cmake ..
```

### Adding External Libraries

Your repo contains `Arlifile` inside the `src` folder. Please [read the documentation](https://github.com/kigster/arli#command-bundle) about the format of `Arlifile`.

Go ahead and edit that file, and under `dependencies:` you want to list all of your libraries by their exact name, and an optional version. 

The best way to do that is to **first search for the library** using the `arli search terms` command. Once you find the library you want, just copy it's name as is into `Arlifile`. If it contains spaces, put quotes around it.

For example:

```bash
❯ arli search /adafruit.*bmp085/i

Arli (1.0.2), Command: search
Library Path: ~/Documents/Arduino/Libraries

Adafruit BMP085 Library                         (1.0.0)    ( 1 total versions )
Adafruit BMP085 Unified                         (1.0.0)    ( 1 total versions )
———————————————————————
  Total Versions : 2
Unique Libraries : 2
———————————————————————
```

If the library is not in the official database, just add it with a name and a url. Arli will use the url field to fetch it.

To verify that your Arlifile can resolve all libraries, please run `arli bundle` inside the `src` folder. If Arli suceeds, you've got it right, and the `libraries` folder inside `src` should contain all referenced libraries.

### Adding Source Files

You will notice that inside `src/CMakeLists.txt` file, there is a line:

```cmake
set(PROJECT_SOURCES NeoRing.cpp)
```

If you add any additional source files or headers, just add their names right after, separated by spaces or newlines. For example:

```cmake
set(PROJECT_SOURCES 
  NeoRing.cpp
  NeoRing.h
  helpers/Loader.cpp
  helpers/Loader.h
  config/Configuration.h
)
```

The should be all you need to do add custom logic and to rebuild and upload the project.

## Where to get Support?

Please feel free to file bug reports and submit pull requests start GitHub — [https://github.com/kigster/arli-cmake](https://github.com/kigster/arli-cmake) is the project URL, and this is the [issues](https://github.com/kigster/arli-cmake/issues) URL.

## License

The original project is distributed as open source, under the terms of the [MIT License](http://opensource.org/licenses/MIT). 

However, feel free to change the license of your project, as long as you provide the credit to the original.

Thanks!
Good luck!


