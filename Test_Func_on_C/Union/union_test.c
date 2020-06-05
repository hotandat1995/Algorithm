#include "call_libs.h"

void print_String(char *Data, int size)
{
  for (int i=0;i<size;i++)
  {
    printf("%.2x",Data[i]);
  }
  printf("\n");
}

void test_union()
{
  union UNI_Test sample;
  sample.Char = 'a';
  printf("Size of Union: %d, data store on that: 0x", (int)sizeof(sample));
  print_String(sample.String, sizeof(sample));

  sample.Int = 2147483647;
  printf("Data: %d\n", sample.Int);
  printf("Size of Union: %d, data store on that: 0x", (int)sizeof(sample));
  print_String(sample.String, sizeof(sample));

  sample.Bool_T = true;
  printf("Size of Union: %d, data store on that: 0x", (int)sizeof(sample));
  print_String(sample.String, sizeof(sample));

  sample.Char = 0x15;
  printf("Size of Union: %d, data store on that: 0x", (int)sizeof(sample));
  print_String(sample.String, sizeof(sample));

  strcpy(sample.String, "12");
  printf("Size of Union: %d, data store on that: 0x", (int)sizeof(sample));
  print_String(sample.String, sizeof(sample));
}
