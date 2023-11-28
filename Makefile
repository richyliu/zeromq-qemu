CFLAGS := -g
LDFLAGS := -T linker.lds

all: main.bin test test2

test: test.c
	$(CC) test.c -lzmq -I/opt/homebrew/include -L/opt/homebrew/lib -o test

test2: test2.c
	$(CC) test2.c -lzmq -I/opt/homebrew/include -L/opt/homebrew/lib -o test2

%.o: %.S
	arm-none-eabi-as $(CFLAGS) -o main.o main.S

main.bin: main.o
	arm-none-eabi-ld $(LDFLAGS) -o main.elf main.o
	arm-none-eabi-objcopy -O binary main.elf main.bin

clean:
	rm -f main.o main.bin main.elf
	rm -f test test2
