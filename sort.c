/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/28 13:03:25 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->head->content > a->head->next->content)
		sa(a);
}

static void	sort_three(t_stack *a)
{
	int		num1;
	int		num2;
	int		max;

	num1 = a->head->content;
	num2 = a->head->next->content;
	max = ft_lstmax(a->head);
	if (num1 == max)
		ra(a);
	else if (num2 == max)
		rra(a);
	sort_two(a);
}

void	sort(t_stack *a, t_stack *b)
{
	t_list	*head_a;
	int		size;

	if (stack_iter(a, stack_is_sorted))
		exit_success(a, b);
	size = a->size;
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		pb(a, b);
		pb(a, b);
		while (size--)
			pb_and_sort_descending(a, b);
		pa_and_sort_ascending(a, b);
	}
	if (stack_iter(a, stack_is_sorted))
		exit_success(a, b);
}

/*
	* static void	sort_three(t_stack *a)
	{
		if (num1 == max)
			then rotate it to the bottom.
		else if (num2 == max)
			then reverse rotate the bottom, make the bottom at top,
			now num2 node is the last one,
		then finally sort 2 between the first and second nodes.
		
	}
*/
