#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
/* Comment this line to run mutex */
#define USING_MUTEX_LOCK

pthread_t thread_id[2];
volatile int counter = 0;
pthread_mutex_t lock;

/* The shared function between 2 thread */
void *trythis(void *arg)
{
#ifndef USING_MUTEX_LOCK
  pthread_mutex_lock(&lock);
#endif
  printf("\nIn arg: %d\n", *(int *)arg);

  uint32_t i = 0;
  counter++;

  printf("\nJob %d has started\n", counter);

  for (i = 0; i < (0xFFFFFFFF); i++)
    ;

  printf("\nJob %d has finished\n", counter);

#ifndef USING_MUTEX_LOCK
  pthread_mutex_unlock(&lock);
#endif
  return NULL;
}

int main(int argc, char **argv)
{
  int i = 0;
  int error;
  int test_in_data = 100;

#ifndef USING_MUTEX_LOCK
  if (pthread_mutex_init(&lock, NULL) != 0)
  {
    printf("\nMutex init has failed\n");
    return 1;
  }
#endif

  while (i < 2)
  {
    error = pthread_create(&thread_id[i], NULL, &trythis, (void *)&test_in_data);
    if (error != 0)
    {
      printf("\nThread can't be created: [%s]", strerror(error));
    }
    i++;
  }

  pthread_join(thread_id[0], NULL);
  pthread_join(thread_id[1], NULL);

#ifndef USING_MUTEX_LOCK
  pthread_mutex_destroy(&lock);
#endif

  return 0;
}