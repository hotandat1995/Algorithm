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
    new_dlist->update_tail = update_tail;

    return new_dlist;
}

/* Function to reverse a Doubly Linked List */
void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *current = *head_ref;

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
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = (Node *)malloc(sizeof(Node));

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

int pop(Node **head_ref)
{
    Node *current = (*head_ref);
    Node *next = NULL;
    int value = 0;

    if (current == NULL)
    {
        printf("List is NULL");
        return value;
    }

    next = current->next;
    value = current->prev->data;

    free(current);
    (*head_ref) = next;

    return value;
}

void free_list(Node **head_ref)
{
    Node *current = (*head_ref);
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void rotate_at(Node **head_ref, int position)
{
    Node *current = (*head_ref);
    Node *next = NULL;
    Node *new_head = NULL;
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
void printList(Node *node)
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

void update_tail(Node **head_ref, Node **tail_ref)
{
    Node *current = (*head_ref);
    Node *temp = NULL;

    while(current != NULL)
    {
        temp = current;
        current = current->next;
    }

    (*tail_ref) = temp;
}