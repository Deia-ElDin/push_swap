/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 02:02:45 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 03:18:15 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_list	*first_node;
	t_list	*second_node;
	t_list	*third_node;

	if (!stack->head || !stack->head->next)
		return ;
	first_node = stack->head;
	second_node = first_node->next;
	third_node = second_node->next;
	first_node->next = third_node;
	second_node->next = first_node;
	first_node->prev = second_node;
	second_node->prev = NULL;
	if (third_node)
		third_node->prev = first_node;
	stack->head = second_node;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

/*
	* void	swap(t_list *stack)
	{
		NOTES:
		1) first_node == first node in the stack.
		2) second_node == second node which is the next of first_node.
		3) third_node == third node which is the next of second_node.
			- We need it incase we have it to we must update it's prev.
			- Cuz it's prev at this point is the second_node.
			- But after we swap, it's prev should be the first_node.
		
		STEPS:
		1) if (!stack->head || !stack->head->next)
			- If there's no head (empty stack),
				or there's first node but there's no second node,
				then there's nothing to swap, just return ;

		2) first_node = stack->head;
		3) second_node = first_node->next;
		4) third_node = second_node->next
			- It will be either a node if we have 
				or NULL if the second_node is the last node.

		NOW WE SWAP:
		We will update the next of each node:
			4) first_node->next = third_node;
				- The first node will go second right?
				- So it's next will be the third_node.
				- Incase we don't have a third node, then the next will be NULL.
			5) second_node->next = first_node;
				- The second node will go first right?
				- So it's next will be the first_node.
		
		We will update the prev of each node:
			6) first_node->prev = second_node;
				- The first node is in the 2nd position right now right?.
				- So it's prev will be the second_node 
					(which is at the 1st position).
			7) second_node->prev = NULL;
				- The second node is now the at the 1st position right?.
				- So it's prev will be NULL.
		
		we will update the prev of the third node if it exists:
			8) if (third_node)
				- If there is a third node, 
					then it's prev should be the first_node right?.
					third_node->prev = first_node

		STACK HEAD PTR:
		7) stack->head = second_node;
			- update the stack to point to the second_node, 
				which is at the 1st position.
	}
*/
