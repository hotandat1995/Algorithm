#include <stdio.h>

int main(int argc, char **argv)
{
  printf("App start!\n");
#ifdef FLAG_BUILD_1
  printf("FLAG_BUILD_1 is enable!\n");
#endif
#ifdef FLAG_BUILD_2
  printf("FLAG_BUILD_2 is enable!\n");
#endif
  printf("App end!\n");
  return 0;
}