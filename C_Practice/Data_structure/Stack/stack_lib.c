#include "stack_lib.h"

stack_t *stack_create(uint32_t capacity)
{
    stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t));
    if (NULL == new_stack)
    {
        printf("Can't allocate stack!\n");
        return NULL;
    }

    new_stack->capacity = capacity;
    new_stack->top = -1;
    new_stack->stack_array = (int *)malloc(sizeof(int) * capacity);

    return new_stack;
}

bool stack_isFull(stack_t *stack)
{
    return (stack->top == (stack->capacity - 1));
}

bool stack_isEmpty(stack_t *stack)
{
    return (stack->top == EMPTY_STACK);
}

bool stack_push(stack_t *stack, int item)
{
    if (stack_isFull(stack))
    {
        printf("Stack is FULL!\n");
        return false;
    }

    stack->stack_array[++stack->top] = item;
    printf("Item %d is pushed to stack!\n", item);

    return true;
}

bool stack_pop(stack_t *stack, int *item)
{
    if (stack_isEmpty(stack))
    {
        printf("Stack is EMPTY!\n");
        *item = INT_MIN;
        return false;
    }

    *item = stack->stack_array[stack->top--];

    return true;
}

bool stack_peek(stack_t *stack, int *item)
{
    if (stack_isEmpty(stack))
    {
        printf("Stack is EMPTY!\n");
        *item = INT_MIN;
        return false;
    }

    return stack->stack_array[stack->top];
}

void stack_free(stack_t *stack)
{
    free(stack->stack_array);
    free(stack);
}