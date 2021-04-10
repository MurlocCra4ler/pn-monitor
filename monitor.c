#include <stdlib.h>
#include <stdio.h>

#include "ethernet.h"

int main (int argc, char * argv[]) {
    uint8_t ip4[4];
    int err;

    err = init_ethernet();
    if (err == -1)
        exit(EXIT_FAILURE);

    get_IP_addr(ip4);
    fprintf(stdout, "started monitor on: %d.%d.%d.%d\n", ip4[0], ip4[1], ip4[2], ip4[3]);

    while (1) {
        handle_requests();
    }
}