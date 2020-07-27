/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MQTT_MESSAGES_H_INCLUDE_GUARD
#define MQTT_MESSAGES_H_INCLUDE_GUARD


#include "mqtt_common.h"

#define _MAX_MSG_SIZE IFGEN_MQTT_MSG_SIZE

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_mqtt_Config 0
#define _MSGID_mqtt_Connect 1
#define _MSGID_mqtt_Disconnect 2
#define _MSGID_mqtt_Send 3
#define _MSGID_mqtt_SendJson 4
#define _MSGID_mqtt_GetConnectionState 5
#define _MSGID_mqtt_AddSessionStateHandler 6
#define _MSGID_mqtt_RemoveSessionStateHandler 7
#define _MSGID_mqtt_AddIncomingMessageHandler 8
#define _MSGID_mqtt_RemoveIncomingMessageHandler 9


// Define type-safe pack/unpack functions for all enums, including included types

// Define pack/unpack functions for all structures, including included types


#endif // MQTT_MESSAGES_H_INCLUDE_GUARD
