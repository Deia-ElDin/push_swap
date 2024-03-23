/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 04:24:45 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*last_node;

	if (!stack->head || !stack->last)
		return ;
	first_node = stack->head;
	second_node = first_node->next;
	last_node = stack->last;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
	second_node->prev = NULL;
	stack->head = second_node;
	stack->last = first_node;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

/*
	* void	rotate(t_stack *stack)
	{
		Notes:
		1) first_node == first node in the stack.
		2) second_node == second node which is the next of first_node.
		3) last_node == last node in the stack.
			- We need it because we must update it's next.
			- We are taking the first node and make it last node right?
			- So the last node next will no longer be NULL,
				it will be the first node.
				and the first node next will be NULL.
		
		STEPS:
		1) if (!stack->head || !stack->last)
			if stack is empty or has only one node, return.
		
		FIRST_NODE:
			2) first_node->next = NULL;
				- We will rotate the first_node to the bottom of the 
					stack right? so the next of first_node will be NULL.
			3) first_node->prev = last_node;
				- the prev of first_node will be last_node.

		LAST_NODE:
			4) last_node->next = first_node;
				- the next of last_node will be first_node.
				and the prev remain the same whatever it's.

		Now what if we have only 2 nodes first and last?
			shouldn't we update the prev of the last node?
				
		SECOND_NODE:
			5) second_node->prev = NULL;
				- The prev of second_node will be NULL.
				- Because it will be the top of the stack right?.
				- Now assume 2 cases:
					1- stack (3, 2, 1) => (2, 1, 3)
						- The prev of the second_node (2) will be NULL.
					2- stack (2, 1) => (1, 2)
						- At this case we must update both nodes, next and prev.
						- The second_node = first_node->next, right?.
						- So the second_node is the same as the last_node, right?
						- We updated the last_node->next to the first_node.
						- And here we will update it's prev to NULL.
						- Because it will be the top of the stack.
					so incase we have 2 or more nodes,
					our implementation still works just fine.

		STACK HEAD & LAST PTRS:
			6) stack->head = second_node;
				- The stack head ptr will point to the second_node,
				- If there's a second_node it will be the head.
				- Else the head will be the last_node.
			7) stack->last = first_node;
				- The stack last ptr will point to the first_node.
	}
*/
