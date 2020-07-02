#include "queue_lib.h"

queue_t *create_queue(uint32_t capacity)
{
  queue_t *new_queue = (queue_t *)malloc(sizeof(queue_t));

  if (NULL == new_queue)
  {
    printf("Can't allocate new queue!\n");
    return NULL;
  }

  new_queue->array = (int *)malloc(sizeof(int) * capacity);

  if (NULL == new_queue->array)
  {
    printf("Can't allocate new buffer for queue!\n");
    return NULL;
  }

  /* Clean buffer before use */
  memset(new_queue->array, 0, sizeof(int) * capacity);

  /* Initalize new data */
  new_queue->capacity = capacity;
  new_queue->front = EMPTY_QUEUE;
  new_queue->size = EMPTY_QUEUE;
  new_queue->rear = new_queue->capacity - 1;

  return new_queue;
}

void free_queue(queue_t *input)
{
  free(input->array);
  free(input);
}

bool isFull(queue_t *queue)
{
  return (queue->size == queue->capacity);
}

bool isEmpty(queue_t *queue)
{
  return (queue->size == EMPTY_QUEUE);
}

bool enqueue(queue_t *queue, int item)
{
  if (isFull(queue))
  {
    printf("Queue is FULL!\n");
    return false;
  }

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = item;
  queue->size++;
  printf("Item %d enqueued to queue!\n", item);

  return true;
}

bool dequeue(queue_t *queue, int *item)
{
  if (isEmpty(queue))
  {
    printf("Queue is EMPTY!\n");
    return false;
  }
  *item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;
  return true;
}

int get_front(queue_t *queue)
{
  if (isEmpty(queue))
  {
    return INT_MIN;
  }

  return queue->array[queue->front];
}

int get_rear(queue_t *queue)
{
  if (isEmpty(queue))
  {
    return INT_MIN;
  }

  return queue->array[queue->rear];
}
