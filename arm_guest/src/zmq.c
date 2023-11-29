#include "zmq.h"

#include "utils.h"

int zmq_recv(char *buf, int len, int blocking) {
    if (blocking) {
        while (!zmq_has_msg()) {
            delay(100);
        }
    }

    if (!zmq_has_msg()) {
        return -1;
    }

    // read message
    int msg_size = HW_ZMQ_MEM(0x0000);
    if (msg_size > len) {
        msg_size = len;
    }
    for (int i = 0; i < msg_size; i++) {
        ((char *)buf)[i] = HW_ZMQ_MEM8(0x100 + i);
    }

    // indicate read
    HW_ZMQ_MEM(0x000c) = 1;
}

int zmq_has_msg() {
    int num_messages = HW_ZMQ_MEM(0x0004);
    return num_messages > 0;
}
