#include <stdint.h>

#include "utils.h"
#include "printf.h"
#include "zmq.h"

void c_entry() {
    int i = 0;
    zmq_set_filter("Hello", 5);
    while (1) {
        char buf[100];
        int len = zmq_recv(buf, 100, 0);
        if (len > 0) {
            printf("Received message: %s\n", buf);
        } else {
            printf("No message available\n");
        }

        char buf2[100];
        memset(buf2, 0, 100);
        int len2 = sprintf(buf2, "Hello, world! %d", i++);
        zmq_send(buf2, len2);
        printf("Sent message: %s\n", buf2);

        delay(1000);
    }
}
