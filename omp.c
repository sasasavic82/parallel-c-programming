#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv)
{
    int i, thread_id, loop_count;

#pragma omp parallel private(thread_id, loop_count)
    {
        loop_count = 0;

#pragma omp for
        for (i = 0; i < 1000; ++i)
            ++loop_count;

        thread_id = omp_get_thread_num();

        printf("Thread %d completed %d iterations.\n", thread_id, loop_count);
    }

    return 0;
}