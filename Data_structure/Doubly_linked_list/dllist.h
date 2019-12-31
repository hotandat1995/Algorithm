#include "stdio.h"
#include "stdlib.h"

/* a node of the doubly linked list */
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Dllist
{
    struct Node *head;
    struct Node *tail;

    void (*reverse)(struct Node **);
    void (*push)(struct Node **, int);
    int (*pop)(struct Node **);
    void (*free_list)(struct Node **);
    void (*rotate_at)(struct Node **, int);
    void (*printList)(struct Node *);
} Dllist;

Dllist *initializeDlist();

void reverse(struct Node **head_ref);
void push(struct Node **head_ref, int new_data);
int pop(struct Node **head_ref);
void free_list(struct Node **head_ref);
void rotate_at(struct Node **head_ref, int position);
void printList(struct Node *node);
