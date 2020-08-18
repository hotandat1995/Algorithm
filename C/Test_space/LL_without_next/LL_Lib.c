#include "LL_lib.h"

bool init_list(Node **head_in, char *input)
{
    Node *head = (Node *)malloc(sizeof(Node));

    if (0 == head)
    {
        printf("Can't Initialize list!\n");
        return false;
    }

    head->buf = (char *)malloc(sizeof(char)*10);
    head->buf = strcpy(head->buf, input);
    head->len = strlen(input);
    head->ref = 0;

    *head_in = head;

    return true;
}

bool append_list(Node *head, char *input)
{
    Node *curr = head;

    /* Travel to the last node*/
    while (curr->ref != 0)
    {
        curr = (Node *)curr->ref;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));

    if (0 == new_node)
    {
        printf("Can't malloc to append list!\n");
        return false;
    }

    curr->ref = (int)new_node;

    new_node->buf = (char *)malloc(sizeof(char)*10);
    new_node->buf = strcpy(new_node->buf, input);
    new_node->ref = 0;
    new_node->len = strlen(input);

    return true;
}

void reverse_list(Node **head_in)
{
    Node *curr = *head_in;
    Node *prev = NULL, *next = NULL;

    /* In case list just have 1 element*/
    if (NULL == curr)
    {
        return;
    }

    while (curr != NULL)
    {
        next = (Node *)curr->ref;
        curr->ref = (Node *)prev;
        prev = curr;
        curr = next;
    }
    *head_in = prev;
}

void print_list(Node *head)
{
    Node *curr = head;
    while (0 != curr->ref)
    {
        printf("String is : %s, len: %d\n", curr->buf, curr->len);
        curr = (Node *)curr->ref;
    }
    printf("String is : %s, len: %d\n", curr->buf, curr->len);
}

void free_list(Node *head_in)
{
    Node *curr = head_in;
    Node *next;

    while (curr != NULL)
    {
        next = (Node *)curr->ref;
        free(curr->buf);
        free(curr);
        curr = next;
    }
}
