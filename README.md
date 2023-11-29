# ZeroMQ QEMU device

## Running baremetal ARM

Run `make`. You will need `arm-none-eabi` GNU build tools. This generates a `main.bin`, which can be ran with QEMU:
``` sh
qemu-system-arm -gdb tcp::2159 -M versatilepb -m 32M -no-reboot -nographic -monitor telnet:127.0.0.1:1234,server,nowait -kernel main.bin
```

Then, connect to the GDB server on QEMU with:
``` sh
arm-none-eabi-gdb -ex 'target remote localhost:2159' -ex 'file main.elf'
```

## Building qemu

make sure to add `LIBRARY_PATH` with where zeromq was installed
```sh
LIBRARY_PATH=/opt/homebrew/lib ../configure --target-list=arm-softmmu 
make LIBRARY_PATH=/opt/homebrew/lib
```
