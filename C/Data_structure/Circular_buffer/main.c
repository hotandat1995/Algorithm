#include "circular_buffer.h"

static cir_buf_handler_t test_handler;

int main(int argc, char **argv)
{
  config_cir_buf_handler(&test_handler, 10);
  for (int i = 0; i < 10; i++)
  {
    test_handler.push_data(test_handler.buffer, i);
  }

  printf("start: %d, end: %d\n",
         test_handler.buffer->start_idx,
         test_handler.buffer->end_idx);

  for (int i = 0; i < 3; i++)
  {
    int32_t temp;
    test_handler.pop_data(test_handler.buffer, &temp);
    printf("%d\n", temp);
  }

  return 0;
}