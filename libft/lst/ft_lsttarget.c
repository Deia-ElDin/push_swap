/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttarget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 06:01:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 04:02:24 by dehamad          ###   ########.fr       */
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

void	ft_lsttarget(t_list *list_a, t_list *list_b, int *max_three)
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
