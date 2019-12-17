#include "Linked_list.h"

void push(Node** head_ref,void *new_data,size_t data_size)
{
    // Allocate memory for new node
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = malloc(data_size);
    new_node->next = (*head_ref);

    // Copy content of new_data to newly allocated memory
    // Assumption: char takes 1 byte
    for(int i = 0; i < data_size; i++)
    {
        *(char*)(new_node->data + i) = *(char*)(new_data+i);
    }

    // Change head pointer as new node is added in beginning
    (*head_ref) = new_node;
}

/*  Function to print nodes in a given linked list. "fptr" is used to access the function to be
    used for printing for current node data. Note that diffirent data types need diffirent specifier
    in printf()
*/

void print_list(Node *node,void (*fptr)(void *))
{
    while(node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to print an interger
void printInt(void *n)
{
    printf(" %d", *(int *)n);
}

// Function to print and float
void printFloat(void *n)
{
    printf(" %f", *(float *)n);
}