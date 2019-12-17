#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"

// Driver program to test above function
int main()
{
    Node *start = NULL;

    //Create and print an Int linked list
    unsigned int_size = sizeof(int);
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 5; i >= 0; i--)
    {
        push(&start, &arr[i], int_size);
    }
    printf("Created integer linked list is:\n");
    print_list(start, printInt);

    unsigned int float_size = sizeof(float);
    float arr_2[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    for (int i = 5; i >= 0; i--)
    {
        push(&start, &arr_2[i], float_size);
    }
    printf("Created float linked list is: \n");
    print_list(start, printFloat);

    return 0;
}