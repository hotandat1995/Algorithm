#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes
{
    void *data;
    struct Nodes *next;
} Node;

void push(Node **head_ref, void *new_data, size_t data_size);
void print_list(Node *node, void (*fptr)(void *));
void printInt(void *n);
void printFloat(void *n);

typedef struct Linked_lists
{
    Node *head;

} Listed;

