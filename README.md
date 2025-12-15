*This project has been created as part of the 42 curriculum by laveerka.*

15th of December, 2025 - Laura Veerkamp

**Description**
Push_swap is a project in which a stack of numbers gets sorted in the smallest possible amount of operations. The program makes use of two stacks, A and B, and rotating, swapping and pushing operations. For my project, I devised a recursive three-way quicksort algorithm. It's a divide-and-conquer approach.

**Instructions**
Mandatory - simply 'make' the project. The executable 'push_swap' takes unique numbers as arguments. The performance of the algorithm is defined by the amount of operations the program takes to fully sort the numbers on stack A. To check the sorting one can make use of the supplied Linux of Mac checker.

```
ARG=$(shuf -i 1-10000 -n 500 | tr '\n' ' '); ./push_swap $ARG
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
./push_swap 794 23 1 764 | ./checker_OS 794 23 1 764
```

Bonus - 'make bonus' the project. The executable 'checker' takes unique numbers as arguments and subsequently waits on valid instructions on standard input. On completing the input by hitting CTRL-D the checker displays OK or KO depending on whether the provided instructions sorted the stack.

**Resources**
I was inspired by a blog post written by [Ulysse Gerkens](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0 "Medium blog post"). It gave me the idea of working with essentially four stacks instead of two (top and bottom per stack). The idea of recursion originated from this blog post as well and the promise of a minimum amount of operations caught my attention.

Apart from the blog post I used the [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer "GitHub repository") written by o-reo to gain insight into the workings of my program. It proved invaluable in understanding what's happening behind the scenes.

**Automation script**
I wrote a bash script to test 1-N numbers X times and have it display the minimum/maximum and average amount of moves per input length.

```
#!/bin/bash

runs=100
max_length=500

for (( length=1; length<=max_length; length++)); do
    
    total=0
    min=999999
    max=0
    
    for (( i=1; i<=runs; i++ )); do
        numbers=$(shuf -i 1-10000 -n $length | tr '\n' ' ')

        echo "$numbers"

        output=$(./push_swap $numbers)
        moves=$(printf "%s\n" "$output" | grep -x -E 'pa|pb|ra|rb|rr|rra|rrb|rrr|sa|sb|ss' | wc -l)
        checker_linux=$(printf "%s\n" "$output" | grep -x -E 'pa|pb|ra|rb|rr|rra|rrb|rrr|sa|sb|ss' | ./checker_linux $numbers)
        (( total += moves))
        (( moves < min )) && min=$moves
        (( moves > max )) && max=$moves
        avg=$(( total / i ))
        echo "Length: $length | Moves: $moves | Checker_linux: $checker_linux | Avg: $avg | Min: $min | Max: $max"

    done
done
```
