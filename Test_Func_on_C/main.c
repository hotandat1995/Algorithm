#include "call_libs.h"

int main(int argc, char **argv) {
  int counter;

  if (argc == 1)
  {
    printf("Nothing pass in this command.");
  }

  if (argc >= 2)
  {
    if (strcmp("memmove", argv[1]) == 0)
    {
      memmove_test();
    }
    else if (strcmp("multi_arg", argv[1]) == 0)
    {
      test_multi_arg();
    }
    else if (strcmp("union", argv[1]) == 0)
    {
      test_union();
    }
    else if (strcmp("union", argv[1]) == 0)
    {
      test_struct();
    }
    else
    {
      printf("Test test con cu chim\n");
    }
  }

  return 0;
}
