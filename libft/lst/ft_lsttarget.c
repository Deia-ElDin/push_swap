/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttarget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 06:01:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 00:17:16 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static	t_list	*ft_set_a_target(t_list *list, int content)
{
	t_list	*closest_node;
	int		closest_diff;
	int		diff;

	closest_node = NULL;
	closest_diff = INT_MAX;
	while (list)
	{
		if (content > list->content)
		{
			diff = content - list->content;
			if (diff <= closest_diff)
			{
				closest_node = list;
				closest_diff = diff;
			}
		}
		list = list->next;
	}
	return (closest_node);
}

// static t_list	*ft_set_b_target(t_list *list, int content)
// {
// 	t_list	*closest_node;
// 	int		closest_diff;
// 	int		diff;
// 	closest_node = NULL;
// 	closest_diff = INT_MAX;
// 	while (list)
// 	{
// 		if (content < list->content)
// 		{
// 			diff = list->content - content;
// 			if (diff < closest_diff)
// 			{
// 				closest_node = list;
// 				closest_diff = diff;
// 			}
// 		}
// 		list = list->next;
// 	}
// 	return (closest_node);
// }


static void	ft_set_a_targets(t_list *list_a, t_list *list_b, int *max_three)
{
	t_list	*target;

	target = NULL;
	while (list_a)
	{
		if (!ft_ismaxthree(list_a->content, max_three))
		{
			target = ft_set_a_target(list_b, list_a->content);
			if (target)
				list_a->target = target;
			else
				list_a->target = ft_lstget_node(list_b, ft_lstmax(list_b));
		}
		else
			list_a->target = NULL;
		list_a = list_a->next;
	}
}

// static void	ft_set_b_targets(t_list *list_b, t_list *list_a)
// {
// 	t_list	*target;
// 	target = NULL;
// 	while (list_b)
// 	{
// 		target = ft_set_b_target(list_a, list_b->content);
// 		if (target)
// 			list_b->target = target;
// 		else
// 			list_b->target = ft_lstget_node(list_a, ft_lstmin(list_a));
// 		list_b = list_b->next;
// 	}
// }

void	ft_lsttarget(t_list *list_a, t_list *list_b, int *max_three)
{
	t_list	*target;

	target = NULL;
	ft_set_a_targets(list_a, list_b, max_three);
	// (void)stack;
	// if (stack == 'a')
	// 	ft_set_a_targets(list_a, list_b);
	// else
	// 	ft_set_b_targets(list_b, list_a);
}
