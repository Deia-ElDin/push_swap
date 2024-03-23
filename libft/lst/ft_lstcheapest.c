/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:14:46 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 02:18:44 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static	void	ft_list_moves(t_list *list, int size)
{
	int	index;

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

static int	ft_get_moves(t_list *list, int a_target)
{
	while (list)
	{
		if (list->content == a_target)
			return (list->moves);
		list = list->next;
	}
	return (0);
}

// static	t_list	*ft_lst_a_cheapest(t_list *list_a, t_list *list_b, int size_a, int *max_three)
// {
// 	t_list	*cheapest_node;
// 	int		cheapest_moves;

// 	cheapest_moves = size_a;
// 	while (list_a)
// 	{
// 		list_a->cheapest = ft_abs(list_a->moves)
// 			+ ft_abs(ft_get_moves(list_b, list_a->target->content));
// 		if ((list_a->content != max_three[0]
// 				|| list_a->content != max_three[1]
// 				|| list_a->content != max_three[2])
// 				 && (list_a->cheapest < cheapest_moves))
// 		{
// 			cheapest_moves = list_a->cheapest;
// 			cheapest_node = list_a;
// 		}
// 		list_a = list_a->next;
// 	}
// 	return (cheapest_node);
// }

// static	t_list	*ft_lst_b_cheapest(t_list *list_b, t_list *list_a, int size_b)
// {
// 	t_list	*cheapest_node;
// 	int		cheapest_moves;

// 	cheapest_moves = size_b;
// 	while (list_b)
// 	{
// 		list_b->cheapest = ft_abs(list_b->moves)
// 			+ ft_abs(ft_get_moves(list_a, list_b->target->content));
// 		if (list_b->cheapest < cheapest_moves)
// 		{
// 			cheapest_moves = list_b->cheapest;
// 			cheapest_node = list_b;
// 		}
// 		list_b = list_b->next;
// 	}
// 	return (cheapest_node);
// }

t_list	*ft_lstcheapest(t_list *list_a, t_list *list_b, int *max_three)
{
	t_list	*cheapest_node;
	int		cheapest_moves;
	int		size_a;
	int		size_b;

	(void)max_three;
	if (!list_a || !list_b)
		return (NULL);
	size_a = ft_lstsize(list_a);
	size_b = ft_lstsize(list_b);
	ft_list_moves(list_a, size_a);
	ft_list_moves(list_b, size_b);
	cheapest_moves = INT_MAX;
	cheapest_node = NULL;
	while (list_a)
	{
		if (list_a->target)
		{
			list_a->cheapest = ft_abs(list_a->moves)
				+ ft_abs(ft_get_moves(list_b, list_a->target->content));
			if (list_a->cheapest < cheapest_moves)
			{
				cheapest_moves = list_a->cheapest;
				cheapest_node = list_a;
			}
		}
		list_a = list_a->next;
	}
	return (cheapest_node);
}

	// if (stack == 'a')
	// 	cheapest_node = ft_lst_a_cheapest(list_a, list_b, size_a);
	// else
	// 	cheapest_node = ft_lst_b_cheapest(list_b, list_a, size_b);