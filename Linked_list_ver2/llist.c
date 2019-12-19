/* llist.c
 * Generic Linked List implementation
 */

#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

llist *llist_create(void *new_data)
{
    struct node *new_node;

    llist *new_list = (llist *)malloc(sizeof(llist));
    *new_list = (struct node *)malloc(sizeof(struct node));

    new_node = *new_list;
    new_node->data = new_data;
    new_node->next = NULL;
    return new_list;
}

void llist_free(llist *list)
{
    struct node *curr = *list;
    struct node *next;

    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);
}

// Returns 0 on failure
int llist_add_inorder(void *data, llist *list,
                      int (*comp)(void *, void *))
{
    struct node *new_node;
    struct node *curr;
    struct node *prev = NULL;

    if (list == NULL || *list == NULL)
    {
        fprintf(stderr, "llist_add_inorder: list is null\n");
        return 0;
    }

    curr = *list;
    if (curr->data == NULL)
    {
        curr->data = data;
        return 1;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;

    // Find spot in linked list to insert new node
    while (curr != NULL && curr->data != NULL && comp(curr->data, data) < 0)
    {
        prev = curr;
        curr = curr->next;
    }
    new_node->next = curr;

    if (prev == NULL)
        *list = new_node;
    else
        prev->next = new_node;

    return 1;
}

void llist_push(llist *list, void *data)
{
    struct node *head;
    struct node *new_node;
    if (list == NULL || *list == NULL)
    {
        fprintf(stderr, "llist_add_inorder: list is null\n");
    }

    head = *list;

    // Head is empty node
    if (head->data == NULL)
        head->data = data;

    // Head is not empty, add new node to front
    else
    {
        new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = head;
        *list = new_node;
    }
}

void *llist_pop(llist *list)
{
    void *popped_data;
    struct node *head = *list;

    if (list == NULL || head->data == NULL)
        return NULL;

    popped_data = head->data;
    *list = head->next;

    free(head);

    return popped_data;
}

void llist_print(llist *list, void (*print)(void *))
{
    struct node *curr = *list;
    while (curr != NULL)
    {
        print(curr->data);
        printf(" ");
        curr = curr->next;
    }
    putchar('\n');
}

void llist_reverse(llist *head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    *head = prev;
}

result_t llist_rotate_from(llist *head, int position)
{
    struct node *pre = NULL;
    struct node *current = *head;
    struct node *end = *head;

    pre = llist_travel_to(head, position - 1);
    if (pre == NULL)
    {
        fprintf(stderr, "llist_rotate_from: Position -1 is invalid!");
        return FAIL;
    }

    current = llist_travel_to(head, position);
    if (pre == NULL)
    {
        fprintf(stderr, "llist_rotate_from: Position is invalid!");
        return FAIL;
    }

    while(end->next != NULL)
    {
        end = end->next;
    }

    pre->next = NULL;
    end->next = *head;

    *head = current;
    return SUCCESS;
}

struct node *llist_travel_to(llist *head, int position)
{
    struct node *current = *head;
    for (int i = 0; i < position; i++)
    {
        // If this position is valid
        if (current->next == NULL)
        {
            fprintf(stderr, "llist_travel: Not avalable position!");
            return NULL;
        }
        else
        {
            current = current->next;
        }
    }
    return current;
}