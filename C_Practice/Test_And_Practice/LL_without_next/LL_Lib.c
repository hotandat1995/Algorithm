#include "LL_lib.h"

bool init_list(Node **head_in,char *input)
{
    Node *head = (Node *)malloc(sizeof(Node));

    if (0 == head)
    {
        printf("Can't Initialize list!\n");
        return false;
    }

    head->buf = input;
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
    curr = new_node;

    curr->ref = 0;
    curr->buf = input;
    curr->len = strlen(input);

    return true;
}

bool remove_ref(int ref_in)
{
    bool result = false;

    return result;
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
