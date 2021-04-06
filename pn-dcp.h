#ifndef _PN_DCP
#define _PN_DCP

#include <inttypes.h>

/* Frame IDs */
#define PN_DCP_FRAME_ID_IDENTIFY 0xFEFE

/* Service IDs */
#define PN_DCP_SERVICE_ID_GET 0x01
#define PN_DCP_SERVICE_ID_SET 0x02
#define PN_DCP_SERVICE_ID_IDENTIFY 0x05

/* Service Types */
#define PN_DCP_SERVICE_TYPE_REQUEST 0x00
#define PN_DCP_SERVICE_TYPE_RESPONSE_SUCCESS 0x01

/* Block Options */

/* IP + Suboptions */
#define PN_DCP_OPTION_IP 0x01

#define PN_DCP_SUBOPTION_MAC_ADDR 0x01
#define PN_DCP_SUBOPTION_IP_ADDR 0x01

/* Device Propertis + Suboptions */
#define PN_DCP_OPTION_DEVICE_PROPS 0x02

#define PN_DCP_SUBOPTION_DEVICE_STATIONNAME 0x02
#define PN_DCP_SUBOPTION_DEVICE_ID 0x03
#define PN_DCP_SUBOPTION_DEVICE_ROLE 0x04
#define PN_DCP_SUBOPTION_DEVICE_PROPS 0x05

typedef struct pn_dcp_frame
{
    uint16_t frame_id;
    uint8_t service_id;
    uint8_t service_type;
    uint32_t x_id;
    uint16_t response_delay;
    uint16_t data_length;
    pn_dcp_block_t blocks[];
} pn_dcp_frame_t;

typedef struct pn_dcp_block
{
    uint8_t option;
    uint8_t suboption;
    uint16_t block_length;
    uint8_t data[];
} pn_dcp_block_t;

#endif