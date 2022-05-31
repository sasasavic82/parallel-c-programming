# C Parallel Programming

Bunch of C examples for multi-threaded and paralell programming.
## Threads (POSIX Threads - PThreads)

POSIX Threads (Pthreads) is a "threads programmin" standard, that defines C types, functions and constants.


In order to `spawn` concurrent units of processing, we can use threads. Those threads are delegated by the operating system and spread across multipe processing cores.

The primary advantage of threads is speed of processing, since all cores of your CPU are utilised.

### Compile & Run:
```
gcc -o threads threads.c -lpthread
./threads
```

## OpenMP (Open Multi-Processing)

OpenMP is an API that implements a multi-threaded, shared memory form of parallelism. 

OpenMP is an automated-way of doing Pthreads, as it takes care of a lot of low-level details you would have to do yourself.

An example parallelises for loops.

### Compile & Run:
```
gcc -fopenmp -o omp omp.c
./omp
```


## MPI (Message Passing Interface)

The Message Passing Interface (MPI) is a standard for implementing parallel programming in C (and in other languages).

It enables the management of allocation, comms, and syncrhonisation of processes mapped on multiple nodes. The nodes can be cores within a CPU, CPUs within a machine or across machines

The MPI interface allows you to manage allocation, communication, and synchronization of a set of processes that are mapped onto multiple nodes, where each node can be a core within a single CPU, or CPUs within a single machine, or even across multiple machines that are networked.

If you are wanting to write super-fast ML training in C, this is where MPI can shine.

The basic MPI program (`mpi.c`) writes a message to the screen indicating which node is running.

MPI programs are compiled using `mpicc`, and are run using `mpirun` with a flag indicating the number of processors to spawn.

### Compile & Run:
```
mpicc mpi.c -o mpi
mpirun -n 5 mpi
```