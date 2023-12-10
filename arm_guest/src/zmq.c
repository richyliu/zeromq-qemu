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

void zmq_send(char *buf, int len) {
    // write message
    for (int i = 0; i < len; i++) {
        HW_ZMQ_MEM8(0x100 + i) = ((char *)buf)[i];
    }

    // indicate write
    HW_ZMQ_MEM(0x0008) = len;
}

int zmq_has_msg() {
    int message_size = HW_ZMQ_MEM(0x0000);
    return message_size >= 0;
}

void zmq_set_filter(char *filter, int len) {
    if (len > 128) {
        len = 128;
    }
    // write filter
    for (int i = 0; i < len; i++) {
        HW_ZMQ_MEM8(0x80 + i) = filter[i];
    }
    // indicate write
    HW_ZMQ_MEM(0x0010) = len;
}
