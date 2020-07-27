

/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MQTTSER_INTERFACE_H_INCLUDE_GUARD
#define MQTTSER_INTERFACE_H_INCLUDE_GUARD


#include "legato.h"

// Internal includes for this interface
#include "mqtt_common.h"
//--------------------------------------------------------------------------------------------------
/**
 * Type for handler called when a server disconnects.
 */
//--------------------------------------------------------------------------------------------------
typedef void (*mqttSer_DisconnectHandler_t)(void *);

//--------------------------------------------------------------------------------------------------
/**
 *
 * Connect the current client thread to the service providing this API. Block until the service is
 * available.
 *
 * For each thread that wants to use this API, either ConnectService or TryConnectService must be
 * called before any other functions in this API.  Normally, ConnectService is automatically called
 * for the main thread, but not for any other thread. For details, see @ref apiFilesC_client.
 *
 * This function is created automatically.
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_ConnectService
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 *
 * Try to connect the current client thread to the service providing this API. Return with an error
 * if the service is not available.
 *
 * For each thread that wants to use this API, either ConnectService or TryConnectService must be
 * called before any other functions in this API.  Normally, ConnectService is automatically called
 * for the main thread, but not for any other thread. For details, see @ref apiFilesC_client.
 *
 * This function is created automatically.
 *
 * @return
 *  - LE_OK if the client connected successfully to the service.
 *  - LE_UNAVAILABLE if the server is not currently offering the service to which the client is
 *    bound.
 *  - LE_NOT_PERMITTED if the client interface is not bound to any service (doesn't have a binding).
 *  - LE_COMM_ERROR if the Service Directory cannot be reached.
 */
//--------------------------------------------------------------------------------------------------
le_result_t mqttSer_TryConnectService
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Set handler called when server disconnection is detected.
 *
 * When a server connection is lost, call this handler then exit with LE_FATAL.  If a program wants
 * to continue without exiting, it should call longjmp() from inside the handler.
 */
//--------------------------------------------------------------------------------------------------
LE_FULL_API void mqttSer_SetServerDisconnectHandler
(
    mqttSer_DisconnectHandler_t disconnectHandler,
    void *contextPtr
);

//--------------------------------------------------------------------------------------------------
/**
 *
 * Disconnect the current client thread from the service providing this API.
 *
 * Normally, this function doesn't need to be called. After this function is called, there's no
 * longer a connection to the service, and the functions in this API can't be used. For details, see
 * @ref apiFilesC_client.
 *
 * This function is created automatically.
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_DisconnectService
(
    void
);


//--------------------------------------------------------------------------------------------------
/**
 * Handler for session state changes
 */
//--------------------------------------------------------------------------------------------------
typedef mqtt_SessionStateHandlerFunc_t mqttSer_SessionStateHandlerFunc_t;


//--------------------------------------------------------------------------------------------------
/**
 * Reference type used by Add/Remove functions for EVENT 'mqttSer_SessionState'
 */
//--------------------------------------------------------------------------------------------------
typedef mqtt_SessionStateHandlerRef_t mqttSer_SessionStateHandlerRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Handler for Incoming message
 */
//--------------------------------------------------------------------------------------------------
typedef mqtt_IncomingMessageHandlerFunc_t mqttSer_IncomingMessageHandlerFunc_t;


//--------------------------------------------------------------------------------------------------
/**
 * Reference type used by Add/Remove functions for EVENT 'mqttSer_IncomingMessage'
 */
//--------------------------------------------------------------------------------------------------
typedef mqtt_IncomingMessageHandlerRef_t mqttSer_IncomingMessageHandlerRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Configure the session
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_Config
(
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
void mqttSer_Connect
(
    const char* LE_NONNULL password
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Close MQTT session
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_Disconnect
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Send data (key, value) to MQTT broker
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_Send
(
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
void mqttSer_SendJson
(
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
int32_t mqttSer_GetConnectionState
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Add handler function for EVENT 'mqttSer_SessionState'
 *
 * This event provides information on session state changes
 */
//--------------------------------------------------------------------------------------------------
mqttSer_SessionStateHandlerRef_t mqttSer_AddSessionStateHandler
(
    mqttSer_SessionStateHandlerFunc_t handlerPtr,
        ///< [IN]
    void* contextPtr
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Remove handler function for EVENT 'mqttSer_SessionState'
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_RemoveSessionStateHandler
(
    mqttSer_SessionStateHandlerRef_t handlerRef
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Add handler function for EVENT 'mqttSer_IncomingMessage'
 *
 * This event provides information on the incoming MQTT message
 */
//--------------------------------------------------------------------------------------------------
mqttSer_IncomingMessageHandlerRef_t mqttSer_AddIncomingMessageHandler
(
    mqttSer_IncomingMessageHandlerFunc_t handlerPtr,
        ///< [IN]
    void* contextPtr
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Remove handler function for EVENT 'mqttSer_IncomingMessage'
 */
//--------------------------------------------------------------------------------------------------
void mqttSer_RemoveIncomingMessageHandler
(
    mqttSer_IncomingMessageHandlerRef_t handlerRef
        ///< [IN]
);

#endif // MQTTSER_INTERFACE_H_INCLUDE_GUARD
