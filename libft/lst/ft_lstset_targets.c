/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset_targets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:15:34 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/28 13:11:43 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static	t_list	*ft_set_target(t_list *list_b, int content)
{
	t_list	*closest_node;
	int		closest_diff;
	int		diff;

	closest_node = NULL;
	closest_diff = INT_MAX;
	while (list_b)
	{
		if (content > list_b->content)
		{
			diff = content - list_b->content;
			if (diff <= closest_diff)
			{
				closest_node = list_b;
				closest_diff = diff;
			}
		}
		list_b = list_b->next;
	}
	return (closest_node);
}

void	ft_lstset_targets(t_list *list_a, t_list *list_b)
{
	t_list	*target;

	while (list_a)
	{
		target = ft_set_target(list_b, list_a->content);
		if (target)
			list_a->target = target;
		else
			list_a->target = ft_lstget_node(list_b, ft_lstmax(list_b));
		list_a = list_a->next;
	}
}

/*
	* void	ft_lstset_targets(t_list *list_a, t_list *list_b)
	{
		the purpose of this function is to set the target node
		for each node in list_a, so we loop over the list_a,
		we call our inner function ft_set_target, 
		target = ft_set_target(list_b, list_a->content);
		we try to find the closest node in list_b to the current list a node.
		if we find a target, we set it to the current node target.
		otherwise, we set the target to the maximum node in list_b,
		so we can rrb afterwards and it's fully sorted.
	}

	* static	t_list	*ft_set_target(t_list *list_b, int content)
	{
		closest_node
			that's the node with a content less then the current node's content.
		closest_diff
			the difference between the current node's content
			and the closest node's content.
		
		while (list_b)
		{
			we loop over the list_b and we check each node content,
			if (content > list_b->content)
				if the content of node of list_a > the content
					of the current node of list_b, then we have a target.
				diff = content - list_b->content;
					we set a new diff for the next comparision.
				if (diff <= closest_diff)
				{
					closest_node = list_b;
						we set the closest node to the current node.
					closest_diff = diff;
						we set the closest diff to the new diff.
				}
			list_b = list_b->next;
				we check the next node and repeat, 
				till we find the perfect node, 
				which is the exact node where we will place our node at
				the top of it.
		}
	}

*/
