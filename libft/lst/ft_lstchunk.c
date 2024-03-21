/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:44:57 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 07:55:53 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstchunk(t_chunk *chunk, t_stack *stack, int pivot, int size)
{
	int		cheapest;
	int		index;

	chunk->cheapest = NULL;
	chunk->len = 0;
	cheapest = size;
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
				chunk->cheapest = stack;
			}
			chunk->len++;
		}
		stack = stack->next;
		index++;
		if (!stack)
			break ;
	}
}
