/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:52:20 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 07:37:43 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *from, t_stack *to)
{
	t_list	*from_top;
	t_list	*from_top_next;
	t_list	*to_top;

	if (!from->head)
		return ;
	from_top = from->head;
	from_top_next = from_top->next;
	to_top = to->head;
	if (from_top_next)
		from_top_next->prev = NULL;
	if (to_top)
	{
		from_top->next = to_top;
		to_top->prev = from_top;
	}
	else
		from_top->next = NULL;
	from->head = from_top_next;
	to->head = from_top;
	if (!to->last)
		to->last = from_top;
	from->size--;
	to->size++;
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

/*
	* void	push(t_list *from, t_list *to)
	{
		NOTES: 
		1) from_top == the first node in the from stack.
		2) from_top_next == the second node in the from stack.
		3) to_top == the first node in the to stack.
		4) We don't need to update the from_top->prev ptr,
			cuz it was NULL already at the from stack,
			and once it's pushed to the to stack, it will be the head,
			so it's prev will remain NULL.
		
		STEPS:
		1) if (!from->head)
			- This check ensures that we got a node in our from stack.
			- If we don't have, then there's nothing to push, so just return ;
			
		2) store the first node (in the from stack) in from_top.
		3) store the second node if it does exist in from_top_next.
			- from_top_next will be either a node or NULL.
		4) store the first node (from the to stack) in to_top.
			- it will be either a node or NULL.
			
		FROM STACK:
			5) if (from_top_next)
				- This means we have more than one node in the from stack.
				- Since we will push the first node from the from stack 
					to the top of the to stack, then our 2nd node (from_top_next)
					will be the new head of the from stack, so it's prev is NULL.

		TO STACK:
			6) if (to_top)
				if to_top exists, if we have any node at the to (stack) then:
				- from_top->next = to_top;
					We  want to push the from_top to the to stack right?. 
					So the next of from_top will be to_top.
				- to_top->prev = from_top;
					The to_top is no longer the head of the to stack right?
					At this point it will be the 2nd node in the to stack.
					So it's prev should be the from_top and no longer NULL.
			7) else if the to stack is empty:
				- from_top->next = NULL;
					The next of from_top will be NULL,
					Cuz it will be the only node in the to stack right?.
		
		STACKS HEADS & LAST PTRS:
			8) from->head = from_top_next;
					- Update the from (stack) head ptr to point to from_top_next.
					- If we have from_top_next 
						then the stack head ptr will point to it right?
					- Else if it was NULL, then the stack head ptr will be NULL.
			9) to->head = from_top;
				- Update the to (stack) head ptr to point
					to the new node (from_top).
			10) if (!to->last);
				- If there's to_last then we leave it as it is.
				- Else it means our to stack was empty,
					so we must update the last ptr to point to the from_top.
					yes both head and last will point to the same node.
					but if we pushed again to the same stack,
					then our condition if (!to->last) will be false,
					and we won't update the last ptr again.
					the purpose of this condition is to update the last ptr
					at the first time we push from stack_a to stack_b.
	}
*/
