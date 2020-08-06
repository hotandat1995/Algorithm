#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

static sem_t sem_lock;

void* shared_func(void* arg)
{
    // Wait here
    sem_wait(&sem_lock);
    printf("Thread number [%d] Enter critical section\n", *(int *)arg);

    // Critical section
    printf("Do something\n");
    sleep(1);

    // Signal
    printf("Out critical section\n");
    sem_post(&sem_lock);
}

int main(int argc, char **argv)
{
    int error;
    int i;
    sem_init(&sem_lock, 0, 1);

    pthread_t thread_id[2];

    for (i=0; i<2;i++)
    {
        error = pthread_create(&thread_id[i], NULL, shared_func, (void *)&i);
        if (error != 0)
        {
          printf("\nThread can't be created: [%s]\n", strerror(error));
        }
    }

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    sem_destroy(&sem_lock);

    return 0;
}