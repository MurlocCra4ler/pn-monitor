#include <stdlib.h>

#include "ethernet.h"

int main (int argc, char * argv[]) {
    int err;

    err = init_ethernet();
    if (err == -1)
        exit(EXIT_FAILURE);

    while (1) {
        handle_requests();
    }
}