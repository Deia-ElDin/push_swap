/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 04:27:03 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*pre_last_node;

	if (!stack->head || !stack->last)
		return ;
	first_node = stack->head;
	last_node = stack->last;
	pre_last_node = last_node->prev;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	pre_last_node->next = NULL;
	stack->head = last_node;
	stack->last = pre_last_node;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

/*
	* void	reverse_rotate(t_stack *stack)
	{
		Notes:
		1) first_node == first node in the stack.
		2) last_node == last node in the stack.
		3) pre_last_node == second node which is the next of first_node.
			- That's the node before the last node.
			- We need it because we must update it's next.
				- We are taking the last node and make it first node right?
				- So the node before last node will no longer point to the 
					last node right? it will be the last node it self.
					so it's next will be NULL.

		STEPS:
		1) if (!stack->head || !stack->last)
			if stack is empty or has only one node, return.
		
		LAST_NODE:
			2) last_node->prev = NULL;
				- The last node will be the head of the stack right?
				- So it's prev should be NULL.
			3) last_node->next = first_node;
				- The next of last_node will be first_node.
				
		FIRST_NODE:
			4) first_node->prev = last_node;
				- The first node is no longer the first node right?.
				- So it's prev will be the last_node & no longer NULL.
				
		PRE_LAST_NODE:
			5) pre_last_node->next = NULL;
				- The next of pre_last_node will be NULL.
				- Because it will the last node of the stack right?.
				- Now assume 2 cases:
					1- stack (3, 2, 1) => (1, 3, 2)
						- The next of the pre_last_node (2) will be NULL.
					2- stack (2, 1) => (1, 2)
						- At this case we must update both nodes, next and prev.
						- The pre_last_node = last_node->prev, right?.
						- So the pre_last_node 
							is the same as the first_node, right?.
						- We updated the first_node->prev to the last_node.
						- And here we will update it's next to NULL.
						- Because it will be the bottom of the stack.
					so incase we have 2 or more nodes,
					our implementation still works just fine.

		STACK HEAD & LAST PTRS:
			6) stack->head = last_node;
				- The stack head ptr will point to the last_node.
			7) stack->last = pre_last_node;
				- The stack last ptr will point to the pre_last_node.
				- If there's a pre_last_node it will be the last.
				- Else the last will be the first_node.
	}
	
*/
