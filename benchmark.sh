#!/bin/bash

# color constants
GREEN='\033[0;32m'
RED='\033[1;91m'
CYAN='\033[1;36m'
RESET='\033[0m' 
YELLOW='\033[0;33m'

# check for input errors
if [ -z "$1" ]; then
    printf "${RED}ERROR${RESET}: No argument provided. Please enter a value for the number of operations greater than 0.\n"
    exit 1
fi

if ! [[ $1 =~ ^[0-9]+$ ]]; then
    printf "${RED}ERROR${RESET}: '$1' is not a valid number. Please enter a valid number for the number of operations.\n"
    exit 1
fi

if [ "$1" -le 0 ]; then
    printf "${RED}ERROR${RESET}: please enter a value for the number of operations greater than 0.\n"
    exit 1
fi

# get num operations argument
num_operations=$1

printf "${YELLOW}Computing naive matrix multiplication...${RESET}\n"
naive_compute_time=$(./naive $num_operations)
printf "${GREEN}done${RESET}\n"
printf "Naive runtime: ${CYAN} ${naive_compute_time} ${RESET} seconds\n\n\n"

printf "${YELLOW}Computing naive parallel matrix multiplication...${RESET}\n"
naive_parallel_compute_time=$(./naive_parallel $num_operations)
printf "${GREEN}done${RESET}\n"
printf "Naive parallel runtime: ${CYAN} ${naive_parallel_compute_time} ${RESET} seconds\n\n\n"

printf "${YELLOW}Computing parallel matrix multiplication...${RESET}\n"
parallel_compute_time=$(./omp $num_operations)
printf "${GREEN}done${RESET}\n"
printf "Parallel runtime: ${CYAN} ${parallel_compute_time} ${RESET} seconds\n\n\n"

naive_parallel_speedup=$(echo "scale=2; $naive_compute_time / $naive_parallel_compute_time" | bc)
parallel_speedup=$(echo "scale=2; $naive_compute_time / $parallel_compute_time" | bc)
printf "Naive parallel speedup: ${CYAN} ${naive_parallel_speedup}x ${RESET}\n"
printf "Parallel speedup: ${CYAN} ${parallel_speedup}x ${RESET}\n\n\n"

#printf "${YELLOW} Computing MPI matrix multiplication...${RESET}\n"
#mpi_compute_time=$(./mpi $num_operations)
#printf "${GREEN}done${RESET}\n"
#printf "MPI runtime: ${CYAN} ${mpi_compute_time} ${RESET} seconds\n"
