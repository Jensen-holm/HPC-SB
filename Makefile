MPICC = mpicc
CC = gcc-12
CFLAGS = -Wall -fopenmp
OBJS = ./Matrix/matrix.c
TARGETS = naive naive_parallel openmp message_passing

all: $(TARGETS)

naive: NORM/naive.c
	$(CC) $(CFLAGS) -o $@ $^ $(OBJS) ./Matrix/Mul/norm_mul.c

naive_parallel: NORM/naive_parallel.c
	$(CC) $(CFLAGS) -o $@ $^ $(OBJS) ./Matrix/Mul/norm_mul.c

openmp: OMP/openmp.c
	$(CC) $(CFLAGS) -o $@ $^ $(OBJS) ./Matrix/Mul/omp_mul.c

message_passing: MPI/message_passing.c
	$(MPICC) $(MPICCFLAGS) -o $@ $^ $(OBJS) ./Matrix/Mul/mpi_mul.c

clean:
	rm -f $(TARGETS)
