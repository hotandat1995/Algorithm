#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_QUEUE 0

typedef struct queue_t
{
    int *array;
    int rear;
    int front;
    int size;
    uint32_t capacity;
} queue_t;

/* Prototype */
queue_t *create_queue(uint32_t capacity);
void free_queue(queue_t *input);
bool isFull(queue_t *queue);
bool isEmpty(queue_t *queue);
bool enqueue(queue_t *queue, int item);
bool dequeue(queue_t *queue, int *item);
int get_front(queue_t *queue);
int get_rear(queue_t *queue);
