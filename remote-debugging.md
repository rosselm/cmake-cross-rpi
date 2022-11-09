# Remote debugging

## Prerequisites on the Raspberry Pi

`sudo apt install gdbserver`

## MacOS

`gdb` needs to be installed.
For this demo GNU gdb (GDB) 12.1 was used.

When getting error messages regarding codesigning then try: https://gcc.gnu.org/onlinedocs/gcc-4.8.1/gnat_ugn_unw/Codesigning-the-Debugger.html.

## Setup

The setup of the tasks and debugger were done according to the following guide provided by Ed Yang: https://github.com/Ed-Yang/rpidebug
In the prelaunch task `gdbserver` an extra step has been added to first copy the binary to the rasperry pi before starting gdbserver:
`"command": "scp ${workspaceFolder}/build/hello pi@raspberrypi.local:/home/pi/ && ssh -L9091:localhost:9091 pi@raspberrypi.local 'gdbserver :9091 ~/hello'",`