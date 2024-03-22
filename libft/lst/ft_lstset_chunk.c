/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstset_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:44:57 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 07:55:53 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstset_chunk(t_list *stack, int pivot, int size)
{
	t_list *ret;
	int		cheapest;
	int		index;

	ret = NULL;
	cheapest = size;
	// cheapest = pivot;
	index = 0;
	while (stack)
	{
		stack->pivot = pivot;
		if (stack->content <= pivot)
		{
			if (index < (size / 2))
				stack->moves = index;
			else
				stack->moves = (size - index) * -1;
			if (ft_abs(stack->moves) < cheapest)
			{
				cheapest = ft_abs(stack->moves);
				ret = stack;
			}
			// if (stack->content <= cheapest)
			// {
			// 	cheapest = stack->content;
			// 	ret = stack;
			// }
			// chunk->len++;
		}
		stack = stack->next;
		index++;
		// if (!stack)
		// 	break ;
	}
	return (ret);
}
