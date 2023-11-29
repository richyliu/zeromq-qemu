#include "uart.h"

static volatile unsigned int *const UART0DR = (unsigned int *)0x101f1000;

void _putchar(const char c) {
    *UART0DR = (unsigned int)(c);
}
