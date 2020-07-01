#pragma ONCE

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int ref;
    int len;
    char *buf;
} Node;

/* Prototype */

bool init_list(Node **head_in, char *input);
bool append_list(Node *head, char *input);

void reverse_list(Node **head_in);
void print_list(Node *head);
void free_list(Node *head_in);