#include "stack_lib.h"

int main(int argc, char **argv)
{
    stack_t *test_stack = stack_create(10);
    printf("Stack is FULL? %s\n", stack_isFull(test_stack) ? "YES" : "NO");
    printf("Stack is EMPTY? %s\n", stack_isEmpty(test_stack) ? "YES" : "NO");

    for (int i = 0; i < 10; i++)
    {
        stack_push(test_stack, i);
    }

    printf("Stack is FULL? %s\n", stack_isFull(test_stack) ? "YES" : "NO");
    printf("Stack is EMPTY? %s\n", stack_isEmpty(test_stack) ? "YES" : "NO");

    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        stack_peek(test_stack, &temp);
        printf("Item %d is peek out stack!\n", temp);
        stack_pop(test_stack, &temp);
        printf("Item %d is poped out stack!\n", temp);
    }

    stack_free(test_stack);
    return 0;
}