#!/bin/bash

runs=1000
min=999999
max=0
length=5

for (( i=1; i<=runs; i++ )); do
    moves=$(./push_swap $(shuf -i 1-10000 -n $length) | wc -l)

    (( moves < min )) && min=$moves
    (( moves > max )) && max=$moves
done

echo "Min: $min"
echo "Max: $max"
