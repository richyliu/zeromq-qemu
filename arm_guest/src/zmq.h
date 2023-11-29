#ifndef ZMQ_H_
#define ZMQ_H_

#include "utils.h"

#define ZMQ_BASE ((void *)0x090c0000)

#define HW_ZMQ_MEM(offset) HWREG32(ZMQ_BASE + offset)
#define HW_ZMQ_MEM8(offset) HWREG8(ZMQ_BASE + offset)

/**
 * Receives a message from ZeroMQ via QEMU. Returns -1 if no message is
 * available.
 */
int zmq_recv(char *buf, int len, int blocking);

/**
 * Returns 1 if there is a message available, 0 otherwise.
 */
int zmq_has_msg();


#endif // ZMQ_H_
