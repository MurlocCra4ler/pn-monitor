#include <stdlib.h>

#include "ethernet.h"

int main (int argc, char * argv[]) {
    init_ethernet();

    while (1) {
        pull_request();
    }
}