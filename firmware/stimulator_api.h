/*
 * shiftx2_api.h
 *
 *  Created on: Feb 4, 2017
 *      Author: brent
 */

#ifndef STIMULATOR_API_H_
#define STIMULATOR_API_H_
#include "ch.h"
#include "hal.h"
#include "system_CAN.h"

struct ConfigGroup1 {
        uint8_t update_rate_hz;
};

/* API offsets */
#define STIMULATOR_CAN_BASE_ID                 0xE4600
#define STIMULATOR_CAN_API_RANGE               256
#define STIMULATOR_CAN_FILTER_MASK             0x1FFFFF00

#define STIMULATOR_DEFAULT_SAMPLE_RATE         DEFAULT_SAMPLE_RATE

/* Configuration and Runtime */

#define API_ANNOUNCEMENT                    0
#define API_RESET_DEVICE                    1
#define API_STATS                           2
#define API_SET_CONFIG_GROUP_1              3

#define API_BROADCAST_SENSORS               20

/* Base API functions */
bool api_is_provisoned(void);
void set_api_is_provisioned(bool);
void api_initialize(void);
void api_set_config_group_1(CANRxFrame *rx_msg);

uint8_t get_sample_rate(void);
void set_sample_rate(uint8_t sample_rate);

void api_send_announcement(void);

#endif /* STIMULATOR_API_H_ */
