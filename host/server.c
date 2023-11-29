//  Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main (void)
{
    printf ("Connecting to hello world server…\n");
    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int ret = zmq_bind(publisher, "tcp://*:5555");
    if (ret != 0) {
        printf("zmq_bind failed\n");
        return 1;
    }

    while (1) {
        printf("Sending Hello\n");
        zmq_send(publisher, "Hello", 5, 0);
        sleep(1);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
