#include <stdint.h>

#include "utils.h"
#include "printf.h"
#include "zmq.h"
#include "exceptions.h"

void c_entry() {
    /* printf("[GUEST]: started\n"); */
    puts("[GUEST]: started");

    // test irq handling
    /* VIC_INTENABLE(VIC_GPIO0); */
    VIC_INTENABLE(0xff);

    for (int i = 0; ; i++) {
        /* printf("[GUEST]: test, counter=%d\n", i); */
        puts("a");
        HW_ZMQ_MEM8(0x11) = 1;
        delay(500);
    }
}
