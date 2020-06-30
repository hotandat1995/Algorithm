#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "LL_lib.h"


int main(int argc, char **argv)
{
    printf("Start app!\n");
    char *input = (char *)malloc(sizeof(char)*10);
    input = strcpy(input, "123456");

    Node *head;
    init_list(&head, input);

    append_list(head, "haha");
    append_list(head, "haha1");
    append_list(head, "haha2");

    print_list(head);
    return 0;
}
