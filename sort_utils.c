/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:13:05 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 02:18:02 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack *stack_a, t_stack *stack_b,
	t_list *cheapest_node)
{
	if (cheapest_node->moves > 0 && cheapest_node->target->moves > 0
		&& cheapest_node->moves-- && cheapest_node->target->moves--)
		rr(stack_a, stack_b);
	else if (cheapest_node->moves < 0 && cheapest_node->target->moves < 0
		&& cheapest_node->moves++ && cheapest_node->target->moves++)
		rrr(stack_a, stack_b);
	else if (cheapest_node->moves > 0 && cheapest_node->moves--)
		ra(stack_a);
	else if (cheapest_node->moves < 0 && cheapest_node->moves++)
		rra(stack_a);
}

void	push_and_sort(t_stack *from, t_stack *to, int *max_three)
{
	t_list	*cheapest_node;

	ft_lsttarget(from->head, to->head, max_three);
	cheapest_node = ft_lstcheapest(from->head, to->head, max_three);
	// printf("stack_a->content: %d\n", from->head->content);
	// printf("stack_b->content: %d\n", to->head->content);
	// printf("cheapest_node->content: %d\n", cheapest_node->content);
	// printf("cheapest_node->moves: %d\n", cheapest_node->moves);
	
	while (cheapest_node && cheapest_node->moves)
		rotate_to_top(from, to, cheapest_node);
	// ft_printf(1, "from a: \n%l\n", from->head);
	// ft_printf(1, "to b: \n%l\n", to->head);
	// printf("cheapest_node->moves: %d\n", cheapest_node->moves);
	if (!cheapest_node->moves)
	{
		while (cheapest_node->target->moves > 0 && cheapest_node->target->moves--)
			rb(to);
		while (cheapest_node->target->moves < 0 && cheapest_node->target->moves++)
			rrb(to);
		pb(from, to);
	}
}


// static void	rotate_to_top_b(t_stack *stack_a, t_stack *stack_b,
// 	t_list *cheapest_node, t_list *target)
// {
// 	if (cheapest_node->moves > 0 && target->moves > 0
// 		&& cheapest_node->moves-- && target->moves--)
// 		rr(stack_a, stack_b);
// 	else if (cheapest_node->moves < 0 && target->moves < 0
// 		&& cheapest_node->moves++ && target->moves++)
// 		rrr(stack_a, stack_b);
// 	else if (cheapest_node->moves > 0 && cheapest_node->moves--)
// 		rb(stack_b);
// 	else if (cheapest_node->moves < 0 && cheapest_node->moves++)
// 		rrb(stack_b);
// }

// void	push_and_sort_b(t_stack *stack_b, t_stack *stack_a)
// {
// 	t_list	*cheapest_node;
// 	t_list	*target;

// 	ft_lsttarget(stack_a->head, stack_b->head, 'b');
// 	cheapest_node = ft_lstcheapest(stack_a->head, stack_b->head, 'b');
// 	ft_printf(1, "stack_a: \n%l\n", stack_a->head);
// 	ft_printf(1, "stack_b: \n%l\n", stack_b->head);
// 	while (cheapest_node->moves)
// 		rotate_to_top_b(stack_b, stack_a, cheapest_node, cheapest_node->target);
// 	if (!cheapest_node->moves)
// 	{
// 		if (cheapest_node->target->moves > 0 && cheapest_node->target->moves--)
// 			ra(stack_a);
// 		else if (cheapest_node->target->moves < 0
// 			&& cheapest_node->target->moves++)
// 			rra(stack_a);
// 		pa(stack_b, stack_a);
// 	}
// }
