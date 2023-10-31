#! /bin/bash

num_operations=$1

echo "\ncomputing naive mat mul ..."
naive_compute_time=$(./naive $num_operations)
echo "naive runtime: ${naive_compute_time} seconds"

echo "\ncomputing parallel mat mul ..."
parallel_compute_time=$(./omp $num_operations)
echo "parallel runtime: ${parallel_compute_time}"

