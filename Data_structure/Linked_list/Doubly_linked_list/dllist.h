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

    void (*reverse)(Node **);
    void (*push)(Node **, int);
    int (*pop)(Node **);
    void (*free_list)(Node **);
    void (*rotate_at)(Node **, int);
    void (*printList)(Node *);
    void (*update_tail)(Node **, Node **);
} Dllist;

Dllist *initializeDlist();

void reverse(Node **head_ref);
void push(Node **head_ref, int new_data);
int pop(Node **head_ref);
void free_list(Node **head_ref);
void rotate_at(Node **head_ref, int position);
void printList(Node *node);
void update_tail(Node **head_ref,Node **tail_ref);

void freeDlist(Dllist **Dlist);

/*  Will implement soon
 - Add tail
 - Insert (anywhere in list)
 - Remove tail
 - Remove (anywhere in list)
*/