CC = gcc-12
CFLAGS = -Wall -fopenmp
SRC_DIR = ./Matrix
OBJS = ./Matrix/mul.c ./Matrix/matrix.c
TARGETS = naive naive_parallel omp

all: $(TARGETS)

naive: $(OBJS) naive.c
	$(CC) $(CFLAGS) $(OBJS) naive.c -o naive

naive_parallel: $(OBJS) naive_parallel.c
	$(CC) $(CFLAGS) $(OBJS) naive_parallel.c -o naive_parallel

omp: openmp.c $(OBJS)
	$(CC) $(CFLAGS) openmp.c -o omp $(OBJS)

clean:
	rm -f $(TARGETS)
