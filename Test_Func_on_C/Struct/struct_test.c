#include "call_libs.h"

typedef struct st_a{
  char string[4];
}st_a;

typedef struct st_b{
  char string[4];
}st_b;

int64_t c;

int64_t test_static_cast()
{
  st_a a = {"abc"};
  st_a *a_p = &a;
  printf("Address of a: 0x%.8lx\n", (uint64_t)a_p);
  printf("String a: %s\n",a.string);

  c = (int64_t)(a_p);
  st_b *b = (st_b *)c;
  strcpy(b->string, "111");
  printf("String a: %s\n",a.string);
  return (int64_t)(c);
}

void get_address_of_struct_after_convert()
{
  printf("Address after convert: 0x%.8lx\n", test_static_cast());
}