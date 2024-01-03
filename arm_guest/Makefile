SRC_DIR := src
BUILD_DIR := build

ASFLAGS := -mcpu=arm926ej-s -g
CFLAGS := -mcpu=arm926ej-s -g -O1 -ffreestanding -nostdlib -nostartfiles
LDFLAGS := -g -l:libgcc.a -L/usr/local/lib/gcc/arm-none-eabi/8.3.1/ -T src/linker.lds

SOURCES := $(wildcard src/*.c)
# objects are built from sources by replacing the .c extension with .o and replacing the src/ prefix with build/
OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

ASMSOURCE := $(wildcard src/*.S)
ASMOBJECTS := $(patsubst $(SRC_DIR)/%.S,$(BUILD_DIR)/%.o,$(ASMSOURCE))

all: $(BUILD_DIR)/main.bin

$(BUILD_DIR)/main.elf: $(ASMOBJECTS) $(OBJECTS)
	arm-none-eabi-ld -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c
	arm-none-eabi-gcc $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: src/%.S
	arm-none-eabi-as $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/main.bin: $(BUILD_DIR)/main.elf
	arm-none-eabi-objcopy -O binary $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.bin

clean:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/main.bin $(BUILD_DIR)/main.elf
