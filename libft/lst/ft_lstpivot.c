/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:06:11 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:02:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static int	ft_diff(int a, int b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

t_list	*ft_lstpivot(t_list *stack)
{
	t_list	*pivot;
	int		middle;
	int		diff;
	int		res;

	middle = ft_lstmax(stack) / 2;
	diff = ft_diff(stack->content, middle);
	stack = stack->next;
	while (stack)
	{
		res = ft_diff(stack->content, middle);
		if (res < diff)
		{
			diff = res;
			pivot = stack;
		}
		stack = stack->next;
	}
	return (pivot);
}
