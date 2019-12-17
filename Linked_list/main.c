#include <stdio.h>
#include<stdlib.h>
#include "Linked_list.h"

struct Node
{
    void *data;
    struct Node *next;
};

void push(struct Node** head_ref,void *new_data,size_t data_size)
{
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

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

void print_list(struct Node *node,void (*fptr)(void *))
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

// Driver program to test above function
int main()
{
    struct Node *start = NULL;

    //Create and print an Int linked list
    unsigned int_size = sizeof(int);
    int arr[] = {1,2,3,4,5,6};
    for(int i = 5;i >= 0; i--)
    {
        push(&start,&arr[i],int_size);
    }
    printf("Created integer linked list is:\n");
    print_list(start, printInt);

    unsigned int float_size = sizeof(float);
    float arr_2[] = {1.1,2.2,3.3,4.4,5.5,6.6};
    for(int i = 5; i >= 0; i--)
    {
        push(&start,&arr_2[i],float_size);
    }
    printf("Created float linked list is: \n");
    print_list(start,printFloat);
    return 0;
}