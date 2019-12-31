/* Program to reverse a doubly linked list */
#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node *head = NULL;

    /* Let us create a sorted linked list to test the functions */
    int number_list[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    for (int i = 0; i < sizeof(number_list) / sizeof(int); i++)
    {
        push(&head, number_list[i]);
    }

    printf(" Original Linked list:\n");
    printList(head);

    /* Reverse doubly linked list */
    reverse(&head);

    printf("\n Reversed Linked list:\n");
    printList(head);

    printf("\n List after pop:\n");
    pop(&head);
    printList(head);

    printf("\n List after rotate at position 2:\n");
    rotate_at(&head, 2);
    printList(head);

    putchar('\n');
    free_list(&head);

    printf("\n Test new list:\n");
    Dllist *doubly_list = initializeDlist();
    for (int i = 0; i < sizeof(number_list) / sizeof(int); i++)
    {
        doubly_list->push(&doubly_list->head, number_list[i]);
    }

    doubly_list->printList(doubly_list->head);

    printf("\nList after reverse:\n");
    doubly_list->reverse(&doubly_list->head);
    doubly_list->printList(doubly_list->head);
}