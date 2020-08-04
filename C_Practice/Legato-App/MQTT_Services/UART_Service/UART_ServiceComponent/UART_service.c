#include "legato.h"
#include "interfaces.h"
#include "packed_data.h"

#define RECEIVER_BUFFER_SIZE 255
#define TIME_DELAY_AFTER_CHECK 200

const char uart_port_name[] = "/dev/ttyHS1";
static le_timer_Ref_t read_uart_port_timer;
static le_timer_Ref_t sent_uart_port_timer;

char buffer[RECEIVER_BUFFER_SIZE];
int port_fd;
volatile bool is_write;

void sent_uart_data()
{
  int bytes_wrote;
  const char test_string[] = "haha\n";

  /* Sent test string */
  bytes_wrote = write(port_fd, test_string, sizeof(test_string));
  if (bytes_wrote < 0)
  {
    LE_ERROR("Sen't fail");
  }
  else
  {
    LE_DEBUG("Write data to UART successed.");
  }
}

void get_uart_data()
{
  /* Read 1 line on file */
  uart_mqtt_message_t *sent_data;
  ssize_t received_size = read(port_fd, buffer, RECEIVER_BUFFER_SIZE);
  if (received_size <= 1)
  {
    LE_DEBUG("Receive nothing");
  }
  else
  {
    buffer[received_size] = '\0';
    LE_INFO("bufsize; %d", received_size);
    sent_data = init_package(buffer, received_size);
    if (sent_data != NULL)
    {
      LE_INFO("Topic: %s", sent_data->topic.topic_data);
      LE_INFO("Content: %s", sent_data->content.content_data);
      LE_INFO("CRC code: 0x%.4x", sent_data->crc_code);

      /* Sent this package to publisher
        if publish success return frame OK to PIN-HUB
        else return frame FAIL to PIN-HUB
      */

      /* Remove the package after use */
      deinit_package(sent_data);
    }
    else
    {
      LE_ERROR("Package is invalid");
    }
  }
}

COMPONENT_INIT
{
  /**
   * Open port to use
   * In this case we use UART2. (Remember set AT!MAPUART=17,2)
   * And the /dev/ttyHS1 will appear check it before run this propram
   */
  port_fd = le_tty_Open(uart_port_name, O_RDWR | O_NOCTTY | O_NDELAY);
  LE_ASSERT(port_fd != -1);

  /* Setup timer to sent data to uart frequently */
  LE_INFO("Create sent UART timer");
  read_uart_port_timer = le_timer_Create("Sent uart port");
  le_timer_SetMsInterval(read_uart_port_timer, TIME_DELAY_AFTER_CHECK);
  le_timer_SetRepeat(read_uart_port_timer, 0);
  le_timer_SetHandler(read_uart_port_timer, sent_uart_data);
  le_timer_Start(read_uart_port_timer);

  /* Setup timer to scan data from uart frequently */
  LE_INFO("Create read UART timer");
  sent_uart_port_timer = le_timer_Create("Read uart port");
  le_timer_SetMsInterval(sent_uart_port_timer, 300);
  le_timer_SetRepeat(sent_uart_port_timer, 0);
  le_timer_SetHandler(sent_uart_port_timer, get_uart_data);
  le_timer_Start(sent_uart_port_timer);
}