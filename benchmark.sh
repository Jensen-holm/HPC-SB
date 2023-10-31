#!/bin/bash

# color constants
RED='\033[1;91m'
GREEN='\033[32m'
CYAN='\033[1;36m'
RESET='\033[0m' 

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

printf "${CYAN}Computing naive matrix multiplication...${RESET}\n\n"
naive_compute_time=$(./naive $num_operations)
printf "${GREEN}Naive runtime:${RESET} ${naive_compute_time} seconds\n\n\n"

printf "${CYAN}Computing parallel matrix multiplication...${RESET}\n\n"
parallel_compute_time=$(./omp $num_operations)
printf "${GREEN}Parallel runtime:${RESET} ${parallel_compute_time} seconds\n\n\n"

