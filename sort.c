/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/25 00:51:04 by dehamad          ###   ########.fr       */
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
	t_list	*head;
	int		num1;
	int		num2;
	int		max;

	head = a->head;
	num1 = a->head->content;
	num2 = a->head->next->content;
	max = ft_lstmax(a->head);
	if (num1 == max)
		ra(a);
	else if (num2 == max)
		rra(a);
	if (a->head->content > a->head->next->content)
		sa(a);
}

static void	sort_above_three(t_stack *a, t_stack *b)
{
	int	size;
	int	*max_three;
	int	pushes;

	size = a->size;
	max_three = ft_lstmax_three(a->head);
	pushes = 0;
	if (!max_three)
		exit_error(a, b);
	while (pushes < 2 && size > 3)
	{
		if (ft_ismaxthree(a->head->content, max_three))
			ra(a);
		else if (++pushes && --size)
			pb(a, b);
	}
	while (size-- > 3)
		push_and_sort(a, b, max_three);
	free(max_three);
	sort_three(a);
	while (b->head && b->head->content != ft_lstmax(b->head))
		rrb(b);
	while (b->head)
		pa(b, a);
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
		sort_above_three(a, b);
	if (stack_iter(a, stack_is_sorted))
		exit_success(a, b);
}
