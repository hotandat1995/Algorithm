
/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MQTTSER_SERVICE_H_INCLUDE_GUARD
#define MQTTSER_SERVICE_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR IFGEN_MQTT_PROTOCOL_ID
#ifdef MK_TOOLS_BUILD
    extern const char** mqttSer_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*mqttSer_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "mqtt"
#endif

#endif // MQTTSER_SERVICE_H_INCLUDE_GUARD
