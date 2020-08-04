#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PUBLISH_START_BYTE       0x06
#define CHECK_FRAME_IS_OK_BYTE   0x01
#define CHECK_FRAME_IS_FAIL_BYTE 0x02

/* Package info*/
#define PACKAGE_SIZE_INDEX_0        2
#define PACKAGE_SIZE_INDEX_1        1
#define TOPIC_SIZE_INDEX_0          4
#define TOPIC_SIZE_INDEX_1          3
#define TOPIC_DATA_START_INDEX      5

/*******************************************************************************
 * Package in:
 *  - start byte: 0x06
 *  - total data lenth: 2 bytes (count after this 2 bytes)
 *  - topic length: 2 bytes
 *  - topic data
 *  - content length: 2 bytes
 *  - content
 *  - CRC code: 2 bytes
 *  - END byte: 0x0D
 ******************************************************************************/
typedef struct topic_t
{
  uint16_t topic_sz;        ///< Topic size
  char     *topic_data;     ///< Pointer hold the topic address
} topic_t;

typedef struct content_t
{
  uint16_t content_sz;      ///< Content size
  char     *content_data;   ///< Pointer hold the content address
} content_t;

/* The package control the message from UART port */
typedef struct uart_mqtt_message_t
{
  topic_t   topic;          ///< Package topic
  content_t content;        ///< Package content
  uint16_t  crc_code;       ///< CRC code of this package
} uart_mqtt_message_t;

/* Prototype */
uint16_t CRC16_2(char *buf, uint32_t len);
uart_mqtt_message_t *init_package(char *buffer, uint32_t buffer_sz);
void deinit_package(uart_mqtt_message_t *package);
