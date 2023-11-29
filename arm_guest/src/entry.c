#include <stdint.h>

#include "utils.h"
#include "printf.h"
#include "zmq.h"

void c_entry() {
    while (1) {
        char buf[100];
        int len = zmq_recv(buf, 100, 0);
        if (len > 0) {
            printf("Received message: %s\n", buf);
        } else {
            printf("No message available\n");
        }
        delay(1000);
    }
}
