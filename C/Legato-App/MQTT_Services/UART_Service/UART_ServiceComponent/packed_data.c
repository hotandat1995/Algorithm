#include "packed_data.h"

/*******************************************************************************
 * Purpose: Generate the CRC code for current frame
 *
 * Param:   crc - CRC code from last frame
 * Param:   frame - Current frame want to calculate the CRC code
 *
 * Return:  The crc calculate from current frame
 *
 ******************************************************************************/
uint16_t cal_crc16(uint16_t crc, uint16_t frame)
{
  const uint16_t poly16 = 0xA001;
  uint16_t lsb;
  uint8_t i;

  crc = ((crc ^ frame) | 0xFF00) & (crc | 0x00FF);
  for (i = 0; i < 8; i++)
  {
    lsb = crc & 0x0001;
    crc = crc / 2;
    if (lsb)
    {
      crc = crc ^ poly16;
    }
  }

  return crc;
}

/*******************************************************************************
 * Purpose: Generate the CRC for the package you want
 *
 * Param:   frame -  Pointe to the package
 * Param:   length - Package size
 *
 * Return:  CRC code
 *
 ******************************************************************************/
uint16_t generate_crc(uint8_t *frame, uint8_t length)
{
  uint16_t crc = 0xFFFF;
  uint8_t i;

  for (i = 0; i < length; i++)
  {
    crc = cal_crc16(crc, frame[i]);
  }

  return crc;
}

/*******************************************************************************
 * @Purpose: This function use to parse the data into raw package we receive
 *           from UART port
 *
 * @Param:   buffer - The pointer point to raw input package
 * @Param:   buffer_sz - The size of input package
 *
 * @Return:  This is the package after parse from raw package data
 *
 ******************************************************************************/
uart_mqtt_message_t *init_package(char *buffer, uint32_t buffer_sz)
{
  uint16_t content_sz_lsb_byte, content_sz_msb_byte;
  uint16_t crc_sz_lsb_byte, crc_sz_msb_byte, crc_of_in_pkg_data;
  uint32_t payload_sz;

  uart_mqtt_message_t *new_package =
      (uart_mqtt_message_t *)malloc(sizeof(uart_mqtt_message_t));

  if (NULL == new_package)
  {
    return NULL;
  }

  /* Get the payload size */
  payload_sz = buffer[PACKAGE_SIZE_INDEX_1] * 256 +
               buffer[PACKAGE_SIZE_INDEX_0];
  printf("payload_sz: %d\n", payload_sz);

  /* Get the topic size */
  new_package->topic.topic_sz = buffer[TOPIC_SIZE_INDEX_1] * 256 +
                                buffer[TOPIC_SIZE_INDEX_0];
  printf("new_package->topic.topic_sz: %d\n", new_package->topic.topic_sz);
  /* Get the content size */
  content_sz_lsb_byte = new_package->topic.topic_sz + 2 + TOPIC_SIZE_INDEX_0;
  content_sz_msb_byte = new_package->topic.topic_sz + 1 + TOPIC_SIZE_INDEX_0;
  printf("lsb: %d, msb: %d\n", content_sz_lsb_byte, content_sz_msb_byte);
  new_package->content.content_sz = buffer[content_sz_msb_byte] * 256 +
                                    buffer[content_sz_lsb_byte];

  printf("new_package->content.content_sz: %d\n",
         new_package->content.content_sz);

  /* Check for package size is equal topic size + content size */
  if (payload_sz !=
      (new_package->topic.topic_sz + new_package->content.content_sz + 4))
  {
    free(new_package);
    return NULL;
  }

  /* Verify the CRC bytes of this package */
  crc_sz_msb_byte = content_sz_msb_byte + new_package->content.content_sz + 2;
  crc_sz_lsb_byte = content_sz_lsb_byte + new_package->content.content_sz + 2;
  crc_of_in_pkg_data = (buffer[crc_sz_msb_byte] << 8) +
                       (buffer[crc_sz_lsb_byte]);
  new_package->crc_code = generate_crc((uint8_t *)buffer, buffer_sz - 3);

  printf("crc gen: 0x%.4x\ncrc input: 0x%.4x\n",
         new_package->crc_code,
         crc_of_in_pkg_data);

  if (crc_of_in_pkg_data != new_package->crc_code)
  {
    free(new_package);
    return NULL;
  }

  /* Add data to struct */
  new_package->topic.topic_data =
      (char *)malloc(sizeof(char) * new_package->topic.topic_sz + 1);
  strncpy(new_package->topic.topic_data,
          &buffer[TOPIC_DATA_START_INDEX],
          new_package->topic.topic_sz);
  new_package->topic.topic_data[new_package->topic.topic_sz] = '\0';

  new_package->content.content_data =
      (char *)malloc(sizeof(char) * new_package->content.content_sz + 1);
  strncpy(new_package->content.content_data,
          &buffer[content_sz_lsb_byte + 1],
          new_package->content.content_sz);
  new_package->content.content_data[new_package->content.content_sz] = '\0';

  return new_package;
}

/*******************************************************************************
 * @Purpose: Free the memory use for this struct
 *
 * @Params:  package - Pointer to package you want to free
 *
 * @Return:  NONE
 *
 ******************************************************************************/
void deinit_package(uart_mqtt_message_t *package)
{
  free(package->topic.topic_data);
  free(package->content.content_data);
  free(package);
}
