CFLAGS := -g
LDFLAGS := -T linker.lds

all: main.bin

%.o: %.S
	arm-none-eabi-as $(CFLAGS) -o main.o main.S

main.bin: main.o
	arm-none-eabi-ld $(LDFLAGS) -o main.elf main.o
	arm-none-eabi-objcopy -O binary main.elf main.bin

clean:
	rm -f main.o main.bin main.elf
