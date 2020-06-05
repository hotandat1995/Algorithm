#include "call_libs.h"

void memmove_test()
{
  uint8_t str_1[5] = {0x40,0x40,0x40,0x40,0x40};
  char str_2[] = "Test String";
  char buffer[100];

  memmove(buffer, (void *)&str_2[0], sizeof(str_2)/sizeof(char));
  printf("%s\n",buffer);
  memmove(buffer, (void *)&str_1[0], sizeof(str_1)/sizeof(char));
  printf("%s\n",buffer);
}