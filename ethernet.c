#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>


#include "ethernet.h"

int raw_sock;

int init_ethernet() {
    raw_sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (raw_sock == -1)
    {
        perror("init_ethernet: socket");
        return -1;
    }

    return 0;
}

void pull_request() {
    
}