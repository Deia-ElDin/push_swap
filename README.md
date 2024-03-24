# Push Swap

## Overview

Push Swap is a project that involves sorting a stack of integers using a limited set of operations on two stacks, such as swapping elements and rotating the stacks. The goal is to implement an algorithm that sorts the stack in the fewest possible operations.

## Moves

The project involves the following moves:

- **sa**: Swap the first two elements of stack A.
- **sb**: Swap the first two elements of stack B.
- **ss**: Apply sa and sb simultaneously.
- **pa**: Push the first element of stack B onto stack A.
- **pb**: Push the first element of stack A onto stack B.
- **ra**: Rotate stack A - move all elements up by one. The first element becomes the last.
- **rb**: Rotate stack B - move all elements up by one. The first element becomes the last.
- **rr**: Apply ra and rb simultaneously.
- **rra**: Reverse rotate stack A - move all elements down by one. The last element becomes the first.
- **rrb**: Reverse rotate stack B - move all elements down by one. The last element becomes the first.
- **rrr**: Apply rra and rrb simultaneously.

## Terminal Commands

Here are the terminal commands used in this project:

- To compile the project: `make`
- To execute the push_swap program: `./push_swap [list of integers] i.e ./push_swap 3 2 1`
- To execute the checker program: `./checker [list of integers]`
- To execute the push_swap program and check the sorting: `$ARG=[list of integers] ./push_swap $ARG | ./checker $ARG`
- To execute the push_swap program with visualizer: `$ARG=[list of integers] ./push_swap $ARG | ./visualizer $ARG`

## Usage

To use this project, follow these steps:

1. Clone the repository.
2. Compile the project using `make`.
3. Execute the push_swap program with a list of integers to be sorted.
4. Optionally, use the checker program to verify the sorting.
5. Enjoy sorting your stack efficiently!

