#include "stdio.h"
#include "stdlib.h"

/* a node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void reverse(struct Node **head_ref);
void push(struct Node **head_ref, int new_data);
int pop(struct Node **head_ref);
void free_list(struct Node **head_ref);
void rotate_at(struct Node **head_ref, int position);
void printList(struct Node *node);
