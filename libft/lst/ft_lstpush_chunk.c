/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_chunk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:07:43 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:02:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"
#include "../../push_swap.h"

void	ft_sort_b(t_list **stack_a, t_list **stack_b, int pivot)
{
	t_list	*node;

	node = *stack_b;
	while (node)
	{
		if (node->content <= pivot)
			pa(stack_b, stack_a);
		else
			rb(stack_b);
		node = *stack_b;
	}
}

void	ft_lstpush_chunk(t_list **from, t_list **to, t_list *node, int pivot)
{
	while (node && node->moves)
	{
		if (node->moves > 0 && node->moves--)
			ra(from);
		else if (node->moves < 0 && node->moves++)
			rra(from);
	}
	if (!node->moves && node->content <= pivot)
		pb(from, to);
}
