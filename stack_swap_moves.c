/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 02:56:10 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*old_first;
	t_stack	*new_first;
	t_stack	*third_node;

	old_first = *stack;
	new_first = (*stack)->next;
	third_node = old_first->next;
	if (!stack || !old_first || !new_first)
		return ;
	old_first->next = new_first->next;
	old_first->prev = new_first;
	new_first->next = old_first;
	new_first->prev = NULL;
	if (third_node)
		third_node->prev = old_first;
	*stack = new_first;
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

/*
	* void	swap(t_stack **stack)
	{
		Notes:
		1) we are taking a double ptrs to stack, so we can modify 
			the original stack inside the function, and that will
			reflect outside.
		2) old_first == first_node;
		3) new_first == second_node;

		Steps:
		1) store the first node in old_first.
		2) store the second node in new_first.
		3) store the third node in third_node.
		4) if (!stack || !old_first || !new_first)
			if stack is empty or has only one node, return.
		5) old_first->next = new_first->next;
			- the next of old_first will be the next of new_first.
		6) old_first->prev = new_first;
			- the prev of old_first will be new_first.
		7) new_first->next = old_first;
			- the next of new_first will be old_first.
		8) new_first->prev = NULL;
			- the prev of new_first will be NULL.
		9) if (third_node)
			if there is a third node, then:
				- third_node->prev = old_first
				- since the old_first is now the second node,
				we update the prev of third_node to old_first.
		10) *stack = new_first;
			- update the stack to point to the new_first.
	}
*/
