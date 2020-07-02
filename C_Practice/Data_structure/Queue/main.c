#include <stdio.h>
#include "queue_lib.h"

int main(int argc, char **argv)
{
    queue_t *test_queue = create_queue(10);

    for (int i = 0 ; i< 10;i++)
    {
        enqueue(test_queue,i);
    }
    enqueue(test_queue,11);

    printf("Rear: %d\n",get_rear(test_queue));
    printf("Front: %d\n",get_front(test_queue));

    printf("Queue is FULL? %s.\n", isFull(test_queue)? "YES":"NO");
    printf("Queue is EMPTY? %s.\n", isEmpty(test_queue)? "YES":"NO");

    return 0;
}