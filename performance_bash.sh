#!/bin/bash

runs=100
min=999999
max=0
length=100

for (( i=1; i<=runs; i++ )); do
    numbers=$(shuf -i 1-10000 -n $length | tr '\n' ' ')

    echo "$numbers"

    output=$(./push_swap $numbers)
    moves=$(printf "%s\n" "$output" | wc -l)
    last_line=$(printf "%s\n" "$output" | tail -n 1)

    (( moves < min )) && min=$moves
    (( moves > max )) && max=$moves
    echo "Moves: $moves | Last: $last_line"
    
done

echo "Min: $min"
echo "Max: $max"
