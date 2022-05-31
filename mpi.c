#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    int rank, proc_num;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &proc_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("Hello World from Node %d of %d\n", (rank + 1), proc_num);

    MPI_Finalize();
    return 0;
}