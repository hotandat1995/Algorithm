#include <stdio.h>
#include <stdlib.h>

#include "Doubly_llist.h"

dllist *dllist_create(void *data)
{
    struct node *new_node;

    dllist *new_list = (dllist *)malloc(sizeof(dllist));
    *new_list = (struct node *)malloc(sizeof(struct node));

    new_node = *new_list;
    new_node->value = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_list;
}

void dllist_free(dllist *dllist)
{
    struct node *curr = *dllist;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(dllist);
}

void dllist_push(dllist *dlist, void *data)
{
    struct node *head;
    struct node *new_node;

    if (dlist == NULL || *dlist == NULL)
    {
        fprintf(stderr, "dllist_push: list is null\n");
    }

    head = *dlist;

    if (head->value == NULL)
        head->value = data;

    else
    {
        new_node = malloc(sizeof(struct node));
        new_node->value = data;
        new_node->next = head;
        new_node->prev = NULL;
        *dlist = new_node;
    }
}

void *dllist_pop(dllist *dlist)
{
    void *popped_data = NULL;
    struct node *head = *dlist;

    if (dlist == NULL || head->value == NULL)
        return NULL;

    popped_data = head->value;
    *dlist = head->next;

    free(head);

    return popped_data;
}

void dllist_print(dllist *list, void (*print)(void *data))
{
    struct node *curr = *list;

    while (curr != NULL)
    {
        print(curr->value);
        printf(" ");
        curr = curr->next;
    }
    putchar('\n');
}

void dllist_reverse(dllist *head)
{
    struct node *current = *head;
    struct node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // while (current != NULL)
    // {
    //     temp = current->next;
    //     printf("temp: %x, ", temp);
    //     current->next = current->prev;
    //     current->prev = temp;
    //     current = temp;
    //     printf("current: %x\n", current);
    // }

    printf("current: %x, head %x, temp: %x\n", current, head, temp);
    *head = temp;
}