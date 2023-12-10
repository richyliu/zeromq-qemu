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
 * Sends a message to ZeroMQ via QEMU.
 */
void zmq_send(char *buf, int len);

/**
 * Returns 1 if there is a message available, 0 otherwise.
 */
int zmq_has_msg();

/**
 * Sets the filter for ZeroMQ message subscriptions.
 */
void zmq_set_filter(char *filter, int len);

#endif // ZMQ_H_
