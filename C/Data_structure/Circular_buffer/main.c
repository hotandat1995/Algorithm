#include "circular_buffer.h"

static cir_buf_handler_t test_handler;

int main(int argc, char **argv)
{
  config_cir_buf_handler(&test_handler, 10);
  for (int i = 7; i < 17+2; i++)
  {
    test_handler.push_data(test_handler.buffer, i);
  }

  for (int i = 0; i < 11; i++)
  {
    int32_t temp;
    test_handler.pop_data(test_handler.buffer, &temp);
    printf("%d\n", temp);
  }

  test_handler.deinit_cir_buf(test_handler.buffer);

  return 0;
}