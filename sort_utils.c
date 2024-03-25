/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:13:05 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/25 08:08:03 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack *a, t_stack *b, t_list *cheapest_node)
{
	int	cheapest;
	int	target;

	cheapest = cheapest_node->moves;
	target = cheapest_node->target->moves;
	if (cheapest > 0 && target > 0 && cheapest-- && target--)
		rr(a, b);
	else if (cheapest < 0 && target < 0 && cheapest++ && target++)
		rrr(a, b);
	else if (cheapest > 0 && cheapest--)
		ra(a);
	else if (cheapest < 0 && cheapest++)
		rra(a);
	cheapest_node->moves = cheapest;
	cheapest_node->target->moves = target;
}

void	push_and_sort(t_stack *a, t_stack *b, int *max_three)
{
	t_list	*cheapest_node;

	ft_lsttarget(a->head, b->head, max_three);
	cheapest_node = ft_lstcheapest(a->head, b->head);
	while (cheapest_node->moves)
		rotate_to_top(a, b, cheapest_node);
	if (!cheapest_node->moves)
	{
		while (cheapest_node->target->moves > 0
			&& cheapest_node->target->moves--)
			rb(b);
		while (cheapest_node->target->moves < 0
			&& cheapest_node->target->moves++)
			rrb(b);
		pb(a, b);
		if (b->head->content == ft_lstmin(b->head))
			rb(b);
	}
}
/*
	ft_printf(1, "\nstack a: \n%l\n", a->head);
	ft_printf(1, "\nstack b: \n%l\n", b->head);
	printf("cheapest_node: %d\n", cheapest_node->content);
*/
