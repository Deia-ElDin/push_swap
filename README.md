# <span style="color:blue">Push Swap</span>

## <span style="color:blue">Overview</span>

Push Swap is a project that involves sorting a stack of integers using a limited set of operations on two stacks, such as swapping elements and rotating the stacks. The goal is to implement an algorithm that sorts the stack in the fewest possible operations.

## <span style="color:blue">Moves</span>

The project involves the following moves:

<span style="color:blue">- sa</span>: Swap the first two elements of stack A.
<span style="color:blue">- sb</span>: Swap the first two elements of stack B.
<span style="color:blue">- ss</span>: Apply sa and sb simultaneously.
<span style="color:blue">- pa</span>: Push the first element of stack B onto stack A.
<span style="color:blue">- pb</span>: Push the first element of stack A onto stack B.
<span style="color:blue">- ra</span>: Rotate stack A - move all elements up by one. The first element becomes the last.
<span style="color:blue">- rb</span>: Rotate stack B - move all elements up by one. The first element becomes the last.
<span style="color:blue">- rr</span>: Apply ra and rb simultaneously.
<span style="color:blue">- rra</span>: Reverse rotate stack A - move all elements down by one. The last element becomes the first.
<span style="color:blue">- rrb</span>: Reverse rotate stack B - move all elements down by one. The last element becomes the first.
<span style="color:blue">- rrr</span>: Apply rra and rrb simultaneously.

## <span style="color:blue">Terminal Commands</span>

Here are the terminal commands used in this project:

- To compile the project: `make`
- To execute the push_swap program: `./push_swap [list of integers] i.e ./push_swap 3 2 1`
- To execute the checker program: `./checker [list of integers]`
- To execute the push_swap program and check the sorting: `$ARG=[list of integers] ./push_swap $ARG | ./checker $ARG`
- To execute the push_swap program with visualizer: `$ARG=[list of integers] ./push_swap $ARG | ./visualizer $ARG`

## <span style="color:blue">Usage</span>

To use this project, follow these steps:

1. Clone the repository.
2. Compile the project using `make`.
3. Execute the push_swap program with a list of integers to be sorted.
4. Optionally, use the checker program to verify the sorting.
5. Enjoy sorting your stack efficiently!
