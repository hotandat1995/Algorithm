#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_STACK -1

typedef struct stack_t
{
  uint32_t top;
  uint32_t capacity;
  int *stack_array;
} stack_t;

/* Prototype */
stack_t *stack_create(uint32_t capacity);
bool stack_isFull(stack_t *stack);
bool stack_isEmpty(stack_t *stack);
bool stack_push(stack_t *stack, int item);
bool stack_pop(stack_t *stack, int *item);
bool stack_peek(stack_t *stack, int *item);
void stack_free(stack_t *stack);
