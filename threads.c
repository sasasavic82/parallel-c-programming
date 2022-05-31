#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_CNT 10

void *the_func(void *num)
{
    int thread_id = *((int *)num);
    printf("Hello World from thread %d!\n", thread_id);
    return NULL;
}

int main(void)
{
    pthread_t threads[THREAD_CNT];
    int th_args[THREAD_CNT];
    int handle, i;

    /* spawn threads */
    for (i = 0; i < THREAD_CNT; ++i)
    {
        th_args[i] = i;
        handle = pthread_create(&threads[i], NULL, the_func, (void *)&th_args[i]);
    }

    /* wait for thread completion */
    for (i = 0; i < THREAD_CNT; ++i)
        handle = pthread_join(threads[i], NULL);

    return 1;
}