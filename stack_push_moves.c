/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:52:20 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 03:22:10 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*from_top;
	t_stack	*from_top_next;
	t_stack	*to_top;

	from_top = *from;
	to_top = *to;
	if (!from || !from_top)
		return ;
	from_top_next = from_top->next;
	if (from_top_next)
		from_top_next->prev = NULL;
	*from = from_top_next;
	to_top->prev = from_top;
	from_top->next = to_top;
	*to = from_top;
}

/*
	* void	push(t_stack **from, t_stack **to)
	{
		Notes:
		1) we are taking double ptrs to stack, so we can modify 
			the original stack inside the function, and that will
			reflect outside.
		2) from_top == first_node from the stack we are pushing from;
		3) to_top == first_node from the stack we are pushing to;
		4) from_top_next == second_node from the stack we are pushing from;

		Steps:
		1) store the first node in from_top.
		2) store the first node in to_top.
		3) if (!from || !from_top)
			- !from: This check ensures that the from pointer itself is not null.
			- !from_top: This check ensures that from_top (the top element of
			the stack) is not null. Even if from (stack) is not null.

		FROM STACK:
			4) store the next node of from_top in from_top_next.
			5) if (from_top_next)
				if from_top_next exists, make its prev NULL.
			6) *from = from_top_next;
				- update the from (stack) ptr to point to from_top_next.

		TO STACK:
			7) to_top->prev = from_top;
				- the prev of to_top will be from_top.
			8) from_top->next = to_top;
				- the next of from_top will be to_top.
			9) *to = from_top;
				- update the to (stack) ptr to point to from_top.
	}
*/
