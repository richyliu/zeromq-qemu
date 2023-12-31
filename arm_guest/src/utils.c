#include "utils.h"

void delay(const int seconds) {
    for (volatile int i = 0; i < seconds; i++) {
        for (volatile int j = 0; j < ONE_SECOND; j++) {
            asm volatile("nop");
        }
    }
}

void memset(void *buf, int val, int len) {
    for (int i = 0; i < len; i++) {
        ((char *)buf)[i] = val;
    }
}
