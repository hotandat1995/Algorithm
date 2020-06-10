#include "call_libs.h"

/* Struct */
typedef struct struct_test{
  char *string;
  int string_size;
  bool is_checked;
} STRUCT_TYPE_1;

typedef struct __attribute__((packed)) struct_test_2{
  char *string;
  int string_size;
  bool is_checked;
} STRUCT_TYPE_2;

void test_struct()
{
  STRUCT_TYPE_1 struct_no_packed;
  STRUCT_TYPE_2 struct_packed;
  printf("---------------------Struct Test---------------------\n");
  printf("Size of STRUCT_TYPE:\n - char *: %d \n - string_size: %d \n - bool: %d\n",
          (int)sizeof(struct_no_packed.string),     /* Size of pointer depend on what  */
          (int)sizeof(struct_no_packed.string_size),
          (int)sizeof(struct_no_packed.is_checked));

  printf("Size of struct_no_packed: %d\n", (int)sizeof(struct_no_packed));
  /* The reason is when you use __attribute__((packed)), It will prevent the padding alignment */
  printf("Size of struct_packed: %d\n", (int)sizeof(struct_packed));
  printf("------------------End Struct Test---------------------\n");
}