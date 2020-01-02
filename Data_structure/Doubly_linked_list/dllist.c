#include "dllist.h"

Dllist *initializeDlist()
{
    Dllist *new_dlist = (Dllist *)malloc(sizeof(Dllist));

    new_dlist->head = NULL;
    new_dlist->tail = NULL;

    new_dlist->reverse = reverse;
    new_dlist->push = push;
    new_dlist->pop = pop;
    new_dlist->free_list = free_list;
    new_dlist->rotate_at = rotate_at;
    new_dlist->printList = printList;

    return new_dlist;
}

/* Function to reverse a Doubly Linked List */
void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = *head_ref;

    /* swap next and prev for all nodes of
       doubly linked list */
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    /* Before changing head, check for the cases like empty
        list and list with only one node */
    if (temp != NULL)
        *head_ref = temp->prev;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data = new_data;

    /* since we are adding at the beginning,
        prev is always NULL */
    new_node->prev = NULL;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int pop(struct Node **head_ref)
{
    struct Node *current = (*head_ref);
    struct Node *next = NULL;
    int value = 0;

    if (current == NULL)
    {
        printf("List is NULL");
        return value;
    }

    next = current->next;
    value = current->prev;

    free(current);
    (*head_ref) = next;

    return value;
}

void free_list(struct Node **head_ref)
{
    struct Node *current = (*head_ref);
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void rotate_at(struct Node **head_ref, int position)
{
    struct Node *current = (*head_ref);
    struct Node *next = NULL;
    struct Node *new_head = NULL;
    int pos = 0;

    while (current != NULL && pos < position - 1)
    {
        current = current->next;
        pos++;
    }

    next = current->next;
    current->next = NULL;

    if (next == NULL)
    {
        return;
    }

    new_head = next;
    new_head->prev = NULL;

    while (next != NULL && next->next != NULL)
    {
        next = next->next;
    }

    next->next = (*head_ref);

    (*head_ref) = new_head;
}

/* Function to print nodes in a given doubly linked list
   This function is same as printList() of singly linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void freeDlist(Dllist **Dlist)
{
    Dllist *thisList = (*Dlist);
    Node *currentNode = thisList->head;
    Node *nextNode = NULL;

    thisList->free_list(&thisList->head);
    thisList->tail = NULL;

    free(thisList);
}