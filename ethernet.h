#ifndef _ETHERNET
#define _ETHERNET

#include <inttypes.h>

typedef struct ethernet_hdr
{
    uint8_t dest[6];
    uint8_t src[6];
    uint16_t type;
} ethernet_hdr_t;


int init_ethernet();

void handle_requests();

#endif