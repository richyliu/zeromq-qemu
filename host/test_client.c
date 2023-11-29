//  Hello World server
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#define ZEROMQ_SUB_ENDPOINT "tcp://localhost:5555"

int main (void) {
    void *context = zmq_ctx_new();
    void *subscriber = zmq_socket(context, ZMQ_SUB);
    int ret = zmq_connect(subscriber, ZEROMQ_SUB_ENDPOINT);
    if (ret != 0) {
        printf("zmq_connect failed\n");
        return 1;
    }
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

    while (1) {
        char buffer[10];
        int recv_size = zmq_recv(subscriber, buffer,
                                10, ZMQ_DONTWAIT);
        if (recv_size != -1) {
            printf("Received %s\n", buffer);
        } else {
            printf("No message received\n");
        }
        sleep(1);
    }
    return 0;
}
