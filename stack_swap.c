/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:02:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*old_first;
	t_list	*new_first;
	t_list	*third_node;

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

void	sa(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

/*
	* void	swap(t_list **stack)
	{
		Notes:
		1) we are taking a double ptrs to stack, so we can modify 
			the original stack inside the function, and that will
			reflect outside.
		2) old_first == first_node;
		3) new_first == second_node;

		Steps:
		1) if (!stack || !old_first || !new_first)
			if stack is empty or has only one node, return.

		OLD_FIRST:
			2) old_first->next = new_first->next;
				- the next of old_first will be the next of new_first.
			3) old_first->prev = new_first;
				- the prev of old_first will be new_first.
			
		NEW_FIRST:
			4) new_first->next = old_first;
				- the next of new_first will be old_first.
			5) new_first->prev = NULL;
				- the prev of new_first will be NULL.

		THIRD_NODE:
		6) if (third_node)
			if there is a third node, then:
				- third_node->prev = old_first
				- since the old_first is now the second node,
				we update the prev of third_node to old_first.
				and the next remain the same whatever it's.

		STACK PTR:
		7) *stack = new_first;
			- update the stack to point to the new_first.
	}
*/
