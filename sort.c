/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 05:38:52 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack_a)
{
	if (stack_a->head->content > stack_a->head->next->content)
		sa(stack_a);
}

static void	sort_three(t_stack *stack_a)
{
	t_list	*head;
	int		num1;
	int		num2;
	int		max;

	head = stack_a->head;
	num1 = stack_a->head->content;
	num2 = stack_a->head->next->content;
	max = ft_lstmax(stack_a->head);
	if (num1 == max)
		ra(stack_a);
	else if (num2 == max)
		rra(stack_a);
	if (stack_a->head->content > stack_a->head->next->content)
		sa(stack_a);
}

static void	sort_above_three(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	*max_three;
	int	pushes;

	size = stack_a->size;
	max_three = ft_lstmax_three(stack_a->head);
	pushes = 0;
	if (!max_three)
		exit_error(stack_a, stack_b);
	while (pushes < 2 && size > 3)
	{
		if (ft_ismaxthree(stack_a->head->content, max_three))
			ra(stack_a);
		else if (++pushes && --size)
			pb(stack_a, stack_b);
	}
	while (size-- > 3)
		push_and_sort(stack_a, stack_b, max_three);
	free(max_three);
	sort_three(stack_a);
	while (stack_b->head && stack_b->head->content != ft_lstmax(stack_b->head))
		rrb(stack_b);
	while (stack_b->head)
		pa(stack_b, stack_a);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*head_a;
	int		size;

	if (stack_iter(stack_a, stack_is_sorted))
		exit_success(stack_a, stack_b);
	size = stack_a->size;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_above_three(stack_a, stack_b);
	if (stack_iter(stack_a, stack_is_sorted))
		exit_success(stack_a, stack_b);
}
