#include "call_libs.h"

#define HELP_PANEL \
"Run \"./main <option>\":\n\
 - memmove: Test memmove function.\n\
 - multi_arg: Test multi argument.\n\
 - union: Test union.\n\
 - struct: Test Struct.\n\
 - func_ptr: Test function ptr combine with struct.\n\
Or you can run \"valgrind ./main <option>\" to check memory leak.\n\
"

int main(int argc, char **argv) {
  int counter;

  if (argc == 1)
  {
    printf("%s", HELP_PANEL);
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
    else if (strcmp("struct", argv[1]) == 0)
    {
      test_struct();
    }
    else if (strcmp("func_ptr", argv[1]) == 0)
    {
      test_func_ptr();
    }
    else
    {
      printf("%s", HELP_PANEL);
    }
  }

  return 0;
}
