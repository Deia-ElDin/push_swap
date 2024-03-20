/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 21:40:00 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*pre_last_node;

	first_node = *stack;
	last_node = ft_lstlast(*stack);
	pre_last_node = last_node->prev;
	if (!stack || !first_node || !last_node)
		return ;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	pre_last_node->next = NULL;
	*stack = last_node;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

/*
	* void	rotate(t_stack **stack)
	{
		Notes:
		1) we are taking a double ptrs to stack, so we can modify 
			the original stack inside the function, and that will
			reflect outside.
		2) first_node == first_node;
		3) second_node == second_node;
		4) last_node == last_node;

		STEPS:
		1) if (!stack || !first_node || !last_node)
			if stack is empty or has only one node, return.
		
		FIRST_NODE:
			2) first_node->next = NULL;
				- we will rotate the first_node to the bottom of the stack,
				so the next of first_node will be NULL.
			3) first_node->prev = last_node;
				- the prev of first_node will be last_node.

		LAST_NODE:
			4) last_node->next = first_node;
				- the next of last_node will be first_node.
				and the prev remain the same whatever it's
				
		SECOND_NODE:
			5) second_node->prev = NULL;
				- the prev of second_node will be NULL.
				- assume:
					1- stack (1, 2, 3) => (2, 3, 1)
						the prev of the second_node will be NULL.
					2- stack (1, 2) => (2, 1)
						the second_node and the last_node are the same,
						so we updated in step 4 the next of the last node,
						and here we will update the prev.
					so incase we have 2 or more nodes,
					our implementation fits all.

		STACK PTR:
		6) *stack = second_node;
			- the stack will be the second_node.
	}

	* void	reverse_rotate(t_stack **stack)
	{
		Notes:
		1) we are taking a double ptrs to stack, so we can modify 
			the original stack inside the function, and that will
			reflect outside.
		2) first_node == first_node;
		3) last_node == last_node;
		4) pre_last_node == the node before the last node in the stack;

		STEPS:
		1) if (!stack || !first_node || !last_node)
			if stack is empty or has only one node, return.
		
		LAST_NODE:
			2) last_node->prev = NULL;
				- the prev of last_node will be NULL.
			3) last_node->next = first_node;
				- the next of last_node will be first_node.
				
		FIRST_NODE:
			4) first_node->prev = last_node;
				- the prev of first_node will be last_node.
				
		PRE_LAST_NODE:
			5) pre_last_node->next = NULL;
				- the next of pre_last_node will be NULL.
				- assume:
					1- stack (1, 2, 3) => (3, 1, 2)
						the next of the pre_last_node will be NULL.
					2- stack (1, 2) => (1, 2)
						the first_node and the pre_last_node are the same,
						so we updated in step 4 the prev of the first node,
						and here we will update the next.
					so incase we have 2 or more nodes,
					our implementation fits all.

		STACK PTR:
		6) *stack = last_node;
			- the stack will be the last_node.
	}
	
*/
