/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:14:46 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/25 08:16:47 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static	void	ft_list_moves(t_list *list)
{
	int	size;
	int	index;

	size = ft_lstsize(list);
	index = 0;
	if (size == 1)
	{
		list->moves = 0;
		list->index = 0;
		return ;
	}
	while (list)
	{
		if (index <= (size / 2))
			list->moves = index;
		else
			list->moves = (size - index) * -1;
		list->index = index++;
		list = list->next;
	}
}

static void	ft_is_valid_different_sign_case(t_list *cheapest_node)
{
	int	smaller_moves;
	int	bigger_moves;
	int	total_moves;
	int	index;

	if (ft_isdifferent_sign(cheapest_node->moves, cheapest_node->target->moves))
	{
		if (abs(cheapest_node->moves) == abs(cheapest_node->target->moves))
			return ;
		if (ft_abs(cheapest_node->moves) < ft_abs(cheapest_node->target->moves))
		{
			smaller_moves = cheapest_node->moves;
			bigger_moves = cheapest_node->target->moves;
			total_moves = ft_abs(smaller_moves) + ft_abs(bigger_moves);
			index = cheapest_node->target->index;
			if ((index - ft_abs(smaller_moves)) <= total_moves)
				cheapest_node->target->moves = index;
			// printf("OUR CASE WORKS 1 \n");
		}
		else
		{
			smaller_moves = cheapest_node->target->moves;
			bigger_moves = cheapest_node->moves;
			total_moves = ft_abs(smaller_moves) + ft_abs(bigger_moves);
			index = cheapest_node->index;
			if ((index - ft_abs(smaller_moves)) <= total_moves)
				cheapest_node->moves = index;
			// printf("OUR CASE WORKS 2 \n");
		}
	}
}
t_list	*ft_lstcheapest(t_list *list_a, t_list *list_b)
{
	t_list	*cheapest_node;
	int		moves;

	if (!list_a || !list_b)
		return (NULL);
	ft_list_moves(list_a);
	ft_list_moves(list_b);
	moves = INT_MAX;
	cheapest_node = NULL;
	while (list_a)
	{
		if (list_a->target)
		{
			list_a->cheapest = ft_abs(list_a->moves)
				+ ft_abs(list_a->target->moves);
			if (list_a->cheapest < moves)
			{
				moves = list_a->cheapest;
				cheapest_node = list_a;
			}
		}
		list_a = list_a->next;
	}
	if (cheapest_node)
		ft_is_valid_different_sign_case(cheapest_node);
	return (cheapest_node);
}
