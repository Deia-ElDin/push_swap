/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 04:43:06 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	first_node = *stack;
	second_node = first_node->next;
	last_node = ft_lstlast(*stack);
	if (!stack || !first_node || !last_node)
		return ;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
	second_node->prev = NULL;
	*stack = second_node;
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
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
	
*/
