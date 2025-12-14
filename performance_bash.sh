#!/bin/bash

runs=100
min=999999
max=0
max_length=500

for (( length=1; length<=max_length; length++)); do
    total=0
    for (( i=1; i<=runs; i++ )); do
        numbers=$(shuf -i 1-10000 -n $length | tr '\n' ' ')

        echo "$numbers"

        output=$(./push_swap $numbers)
        moves=$(printf "%s\n" "$output" | grep -x -E 'pa|pb|ra|rb|rr|rra|rrb|rrr|sa|sb|ss' | wc -l)
        #last_line=$(printf "%s\n" "$output" | tail -n 1)
        checker_linux=$(printf "%s\n" "$output" | grep -x -E 'pa|pb|ra|rb|rr|rra|rrb|rrr|sa|sb|ss' | ./checker_linux $numbers)
        (( total += moves))
        (( moves < min )) && min=$moves
        (( moves > max )) && max=$moves
        avg=$(( total / i ))
        echo "Length: $length | Moves: $moves | Checker_linux: $checker_linux | Avg: $avg"

    done
done

avg=$(( total / runs ))

echo "Min: $min"
echo "Max: $max"
echo "Avg: $avg"
