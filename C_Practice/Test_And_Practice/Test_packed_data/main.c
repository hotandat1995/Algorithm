#include "packed_data.h"

uint8_t input_buffer[] =
    {0x06,                         ///< Start byte
     0x00, 0x0F,                   ///< Total length
     0x00, 0x06,                   ///< Topic length
     0x41, 0x41, 0x41, 0x41, 0x41, 0x41, ///< Topic data
     0x00, 0x05,                   ///< Content length
     0x42, 0x42, 0x42, 0x42, 0x42, ///< Content data
     0x06, 0x55};                  ///< CRC code

int main(int argc, char **argv)
{
  uart_mqtt_message_t *test_package;
  test_package = init_package(input_buffer, sizeof(input_buffer));

  if (test_package == NULL)
  {
    printf("Initialize is failled!\n");
  }
  else
  {
    printf("Topic is: %s\nTopic size is: %d\n",
           test_package->topic.topic_data,
           test_package->topic.topic_sz);
    printf("Content is: %s\nContent size is: %d\n",
           test_package->content.content_data,
           test_package->content.content_sz);
  }

  return 0;
}