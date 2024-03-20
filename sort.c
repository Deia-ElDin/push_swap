/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/20 22:04:18 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **stack_a)
{
	int	num1;
	int	num2;
	int	max;

	num1 = (*stack_a)->content;
	num2 = (*stack_a)->next->content;
	max = ft_lstmax(*stack_a);
	if (num1 == max)
		ra(stack_a);
	else if (num2 == max)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

static void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_node;
	int		min;

	while (*stack_a && ft_lstsize(*stack_a) > 3)
	{
		last_node = ft_lstlast(*stack_a);
		min = ft_lstmin(*stack_a);
		if ((*stack_a)->content == min)
			pb(stack_a, stack_b);
		else if (last_node->prev->content == min)
			(rra(stack_a), rra(stack_a));
		else if (last_node->content == min)
			rra(stack_a);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

static void	sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*pivot;

	(void)stack_b;
	pivot = ft_lstpivot(*stack_a);
	printf("pivot: %d\n", pivot->content);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (stack_iter(*stack_a, stack_is_sorted))
		exit_success(*stack_a, *stack_b);
	size = ft_lstsize(*stack_a);
	if (size == 2 && ((*stack_a)->content > (*stack_a)->next->content))
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else if (size <= 100)
		sort_hundred(stack_a, stack_b);
	if (stack_iter(*stack_a, stack_is_sorted))
		exit_success(*stack_a, *stack_b);

	// else
	// 	sort_five_hundred(stack_a, stack_b);
}

// ./push_swap 83 97 54 13 44 82 19 77 23 91 15 68 62 34 6 49 1 70 25 81 28 10 29 88 51 73 14 87 58 16 80 98 42 99 20 17 84 27 76 93 50 61 43 22 2 45 48 39 36 72 3 47 85 40 71 79 86 24 37 53 95 41 69 38 63 8 26 9 7 12 78 31 74 5 66 67 65 32 33 89 55 64  