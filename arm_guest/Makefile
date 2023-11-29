SRC_DIR := src
BUILD_DIR := build

ASFLAGS := -mcpu=arm926ej-s -g
CFLAGS := -mcpu=arm926ej-s -g -O1
LDFLAGS := -g -l:libgcc.a -L/usr/local/lib/gcc/arm-none-eabi/8.3.1/
FINAL_LDFLAGS := -T src/linker.lds $(LDFLAGS)

SOURCES := $(wildcard src/*.c)
# objects are built from sources by replacing the .c extension with .o and replacing the src/ prefix with build/
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

all: build/main.bin

build/main.o: $(OBJECTS)
	arm-none-eabi-ld $(LDFLAGS) -r -o $@ $^

build/%.o: src/%.c
	arm-none-eabi-gcc $(CFLAGS) -c -o $@ $<

build/main.bin: build/main.o src/startup.S src/linker.lds
	arm-none-eabi-as $(ASFLAGS) -o src/startup.o src/startup.S
	arm-none-eabi-ld -o build/main.elf src/startup.o build/main.o $(FINAL_LDFLAGS)
	arm-none-eabi-objcopy -O binary build/main.elf build/main.bin

clean:
	rm -f build/*.o
	rm -f build/main.bin build/main.elf
