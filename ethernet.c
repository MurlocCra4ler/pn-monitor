#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/ethernet.h>
#include <linux/if.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>


#include "ethernet.h"

int raw_sock;
uint8_t buffer[65536];

int init_ethernet() {
    raw_sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (raw_sock == -1)
    {
        perror("init_ethernet: socket");
        return -1;
    }

    return 0;
}

int get_IP_addr(uint8_t ip_addr[]) {
    struct ifreq ifr;
    int err;

    ifr.ifr_addr.sa_family = AF_PACKET;
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);
    err = ioctl(raw_sock, SIOCGIFADDR, &ifr);
    if (err == -1) {
        return -1;
    }

    uint32_t *addr = (uint32_t *)ip_addr;
    addr[0] = ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr;

    return 0;
}

void handle_requests() {
    int flags;
    int packet_size;
    int retries = 10;

    flags = MSG_DONTWAIT;

    while (retries)
    {
        packet_size = recvfrom(raw_sock, buffer, 65536, flags, NULL, NULL);
        if (packet_size == -1) {
            /* nothing to do */
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                break;
            }
            
            perror("handle_requests: recvfrom");
            retries -= 1;
            continue;
        }

        ethernet_hdr_t *hdr = (ethernet_hdr_t *)buffer;
        fprintf(stdout, "destination: %d:%d:%d:%d:%d:%d\n", hdr->dest[0], hdr->dest[1], hdr->dest[2], hdr->dest[3], hdr->dest[4], hdr->dest[5]);
        fprintf(stdout, "source: %d:%d:%d:%d:%d:%d\n", hdr->src[0], hdr->src[1], hdr->src[2], hdr->src[3], hdr->src[4], hdr->src[5]);
        fprintf(stdout, "type: %d\n\n", htons(hdr->type));

        /* TODO handle request */

    }
}