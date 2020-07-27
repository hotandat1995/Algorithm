
/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */
#ifndef MQTT_COMMON_H_INCLUDE_GUARD
#define MQTT_COMMON_H_INCLUDE_GUARD


#include "legato.h"

#define IFGEN_MQTT_PROTOCOL_ID "d3786ed95c09e37a9fbd18060406bc1c"
#define IFGEN_MQTT_MSG_SIZE 2060



//--------------------------------------------------------------------------------------------------
/**
 * Reference type used by Add/Remove functions for EVENT 'mqtt_SessionState'
 */
//--------------------------------------------------------------------------------------------------
typedef struct mqtt_SessionStateHandler* mqtt_SessionStateHandlerRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Reference type used by Add/Remove functions for EVENT 'mqtt_IncomingMessage'
 */
//--------------------------------------------------------------------------------------------------
typedef struct mqtt_IncomingMessageHandler* mqtt_IncomingMessageHandlerRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Handler for session state changes
 */
//--------------------------------------------------------------------------------------------------
typedef void (*mqtt_SessionStateHandlerFunc_t)
(
        bool isConnected,
        ///< Session State: connected or disconnected
        int32_t connectErrorCode,
        ///< connection returned code
        int32_t subErrorCode,
        ///< subscribe returned code
        void* contextPtr
        ///<
);

//--------------------------------------------------------------------------------------------------
/**
 * Handler for Incoming message
 */
//--------------------------------------------------------------------------------------------------
typedef void (*mqtt_IncomingMessageHandlerFunc_t)
(
        const char* LE_NONNULL topicName,
        ///< Name of the subscribed topic
        const char* LE_NONNULL key,
        ///< Key Name of the data
        const char* LE_NONNULL value,
        ///< Value of the data
        const char* LE_NONNULL timestamp,
        ///< Timestamp of the data
        void* contextPtr
        ///<
);


//--------------------------------------------------------------------------------------------------
/**
 * Get if this client bound locally.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED bool ifgen_mqtt_HasLocalBinding
(
    void
);


//--------------------------------------------------------------------------------------------------
/**
 * Init data that is common across all threads
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_InitCommonData
(
    void
);


//--------------------------------------------------------------------------------------------------
/**
 * Perform common initialization and open a session
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_mqtt_OpenSession
(
    le_msg_SessionRef_t _ifgen_sessionRef,
    bool isBlocking
);

//--------------------------------------------------------------------------------------------------
/**
 * Configure the session
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_Config
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        const char* LE_NONNULL brokerUrl,
        ///< [IN]
        int32_t portNumber,
        ///< [IN]
        int32_t keepAlive,
        ///< [IN]
        int32_t QoS
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Open a MQTT session
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_Connect
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        const char* LE_NONNULL password
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Close MQTT session
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_Disconnect
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * Send data (key, value) to MQTT broker
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_Send
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        const char* LE_NONNULL key,
        ///< [IN]
        const char* LE_NONNULL value,
        ///< [IN]
        int32_t* errCodePtr
        ///< [OUT]
);

//--------------------------------------------------------------------------------------------------
/**
 * Send JSON data (JSON) to MQTT broker
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_SendJson
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        const char* LE_NONNULL json,
        ///< [IN]
        int32_t* errCodePtr
        ///< [OUT]
);

//--------------------------------------------------------------------------------------------------
/**
 * Get mqtt connection state - useful for manual query
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED int32_t ifgen_mqtt_GetConnectionState
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * Add handler function for EVENT 'mqtt_SessionState'
 *
 * This event provides information on session state changes
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED mqtt_SessionStateHandlerRef_t ifgen_mqtt_AddSessionStateHandler
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        mqtt_SessionStateHandlerFunc_t handlerPtr,
        ///< [IN]
        void* contextPtr
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Remove handler function for EVENT 'mqtt_SessionState'
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_RemoveSessionStateHandler
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        mqtt_SessionStateHandlerRef_t handlerRef
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Add handler function for EVENT 'mqtt_IncomingMessage'
 *
 * This event provides information on the incoming MQTT message
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED mqtt_IncomingMessageHandlerRef_t ifgen_mqtt_AddIncomingMessageHandler
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        mqtt_IncomingMessageHandlerFunc_t handlerPtr,
        ///< [IN]
        void* contextPtr
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Remove handler function for EVENT 'mqtt_IncomingMessage'
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_mqtt_RemoveIncomingMessageHandler
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        mqtt_IncomingMessageHandlerRef_t handlerRef
        ///< [IN]
);

#endif // MQTT_COMMON_H_INCLUDE_GUARD
