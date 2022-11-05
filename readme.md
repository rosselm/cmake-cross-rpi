# Cross compilation for Raspberry Pi

## Introduction

This setup has been tested on a Raspberry Pi 4:

```bash
pi@raspberrypi:~ $ date
Sat Nov  5 17:48:05 CET 2022
pi@raspberrypi:~ $ cat /etc/os-release
PRETTY_NAME="Raspbian GNU/Linux 11 (bullseye)"
NAME="Raspbian GNU/Linux"
VERSION_ID="11"
VERSION="11 (bullseye)"
VERSION_CODENAME=bullseye
ID=raspbian
ID_LIKE=debian
HOME_URL="http://www.raspbian.org/"
SUPPORT_URL="http://www.raspbian.org/RaspbianForums"
BUG_REPORT_URL="http://www.raspbian.org/RaspbianBugs"
pi@raspberrypi:~ $ uname -a
Linux raspberrypi 5.15.61-v7l+ #1579 SMP Fri Aug 26 11:13:03 BST 2022 armv7l GNU/Linux
```

Cross compiling C++20 for the Raspberry Pi on MacOS was the goal of this project.

Things can probably be made better on the CMake level. Feel free to comment.

## Prerequisites

### Sysroot

To cross-compile you need a mirror of the files on your raspberry pi (libs, header files, ...).

Usually using rsync is the easiest way to achieve this.
For this project the following rsync commands were used:

```bash
export MY_PI_SYSROOT=$HOME/pisysroot
rsync -rzLR --safe-links pi@raspberrypi.local:/usr/lib/arm-linux-gnueabihf pi@raspberrypi.local:/usr/lib/gcc/arm-linux-gnueabihf pi@raspberrypi.local:/usr/include pi@raspberrypi.local:/lib/arm-linux-gnueabihf $MY_PI_SYSROOT/

rsync -vrzLR --safe-links --include 'ld*' --include 'lib*' --exclude '*'  pi@raspberrypi.local:/lib sysroot/

# to include usr headers like wiringPi.h, pigpio
rsync -vrzLR --safe-links --include 'wiringPi*' --exclude '/usr/include/*'  pi@raspberrypi.local:/usr/include $MY_PI_SYSROOT/
# to include usr libs like wiringpi, pigpio
rsync -vrzLR --safe-links --include 'libwiringPi*' --exclude '/usr/lib/*'  pi@raspberrypi.local:/usr/lib $MY_PI_SYSROOT/
```

### Toolchain

This setup has been tested with 

```
Homebrew clang version 15.0.3
Target: x86_64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /usr/local/opt/llvm/bin
```

and the arm-linux-gnueabihf-binutils toolchain.

On the Mac you can install both of those with:
- brew install clang
- brew install arm-linux-gnueabihf-binutils

To get the base paths of both installations on your Mac use:
- brew --prefix llvm 
- brew --prefix arm-linux-gnueabihf-binutils

For the purpose of this project the sysroot is located at `$HOME/pisysroot`. This is also used in above rsync (`export MY_PI_SYSROOT=$HOME/pisysroot`)

### CMake toolchain file

To tell CMake you are in cross-compilation land you need a toolchain file you can refere to from the command line or from the root CMakeLists.txt.

For example you can put a rpi-toolchain.cmake in your home directory.
For the purpose of this project the toolchain cmake file is located at `$HOME/rpi-toolchain.cmake`.

After the above preparations you can now build C++20 for the Raspberry Pi using this example repo.
