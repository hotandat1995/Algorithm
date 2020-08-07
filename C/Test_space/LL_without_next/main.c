#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "LL_lib.h"

int main(int argc, char **argv)
{
  printf("Start app!\n");

  Node *head;
  init_list(&head, "haha0");

  append_list(head, "haha1");
  append_list(head, "haha2");
  append_list(head, "haha3");

  print_list(head);

  printf("List after reverse:\n");
  reverse_list(&head);
  print_list(head);

  free_list(head);

  printf("Done app!\n");
  return 0;
}
