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

    sleep(2);

    int idx = 0;
    while (1) {
        char buf[100];
        sprintf(buf, "Hello %d", idx++);
        printf("Sending message: '%s'\n", buf);
        zmq_send(publisher, buf, strlen(buf), 0);
        sleep(1);
    }

    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}
