#!/bin/bash

if [ -z "$1" ]; then
    echo "No argument provided. Please enter a value for the number of operations greater than 0."
    exit 1
fi

if ! [[ $1 =~ ^[0-9]+$ ]]; then
    echo "$1 is not a valid number. Please enter a valid number for the number of operations."
    exit 1
fi

if [ $1 -le 0 ]; then
    echo "Enter a value for the number of operations greater than 0."
    exit 1
fi

num_operations=$1

echo
echo "Computing naive matrix multiplication..."
naive_compute_time=$(./naive $num_operations)
echo "Naive runtime: ${naive_compute_time} seconds"

echo
echo "Computing parallel matrix multiplication..."
parallel_compute_time=$(./omp $num_operations)
echo "Parallel runtime: ${parallel_compute_time} seconds"

