#!/bin/bash

# color constants
RED='\033[1;91m'
GREEN='\033[32m'
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

if [ $1 -le 0 ]; then
    printf "${RED}ERROR${RESET}: please enter a value for the number of operations greater than 0.\n"
    exit 1
fi

# get num operations argument
num_operations=$1

printf "${YELLOW}Computing naive matrix multiplication...${RESET}\n\n"
naive_compute_time=$(./naive $num_operations)
printf "Naive runtime: ${CYAN} ${naive_compute_time} ${RESET} seconds\n\n\n"

printf "${YELLOW}Computing parallel matrix multiplication...${RESET}\n\n"
parallel_compute_time=$(./omp $num_operations)
printf "Parallel runtime: ${CYAN} ${parallel_compute_time} ${RESET} seconds\n\n\n"

