/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:13:05 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 22:50:15 by dehamad          ###   ########.fr       */
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
	ft_printf(1, "\nlist_a: \n%l\n", from->head);
	ft_printf(1, "\nlist_b: \n%l\n", to->head);
	cheapest_node = ft_lstcheapest(from->head, to->head, max_three);
	ft_printf(1, "\nlist_a: \n%l\n", from->head);
	ft_printf(1, "\nlist_b: \n%l\n", to->head);
	while (cheapest_node && cheapest_node->moves)
		rotate_to_top(from, to, cheapest_node);
	ft_printf(1, "\nlist_a: \n%l\n", from->head);
	ft_printf(1, "\nlist_b: \n%l\n", to->head);
	if (!cheapest_node->moves)
	{
		while (cheapest_node->target->moves > 0
			&& cheapest_node->target->moves--)
			rb(to);
		while (cheapest_node->target->moves < 0
			&& cheapest_node->target->moves++)
			rrb(to);
		pb(from, to);
		if (to->head->content == ft_lstmin(to->head))
			rb(to);
	}
	ft_printf(1, "\nlist_a: \n%l\n", from->head);
	ft_printf(1, "\nlist_b: \n%l\n", to->head);
}
