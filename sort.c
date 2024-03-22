/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:21:43 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	sort_three(t_list **stack_a)
// {
// 	int	num1;
// 	int	num2;
// 	int	max;

// 	num1 = (*stack_a)->content;
// 	num2 = (*stack_a)->next->content;
// 	max = ft_lstmax(*stack_a);
// 	if (num1 == max)
// 		ra(stack_a);
// 	else if (num2 == max)
// 		rra(stack_a);
// 	if ((*stack_a)->content > (*stack_a)->next->content)
// 		sa(stack_a);
// }

// static void	sort_five(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*last_node;
// 	int		min;

// 	while (*stack_a && ft_lstsize(*stack_a) > 3)
// 	{
// 		last_node = ft_lstlast(*stack_a);
// 		min = ft_lstmin(*stack_a);
// 		if ((*stack_a)->content == min)
// 			pb(stack_a, stack_b);
// 		else if (last_node->prev->content == min)
// 			(rra(stack_a), rra(stack_a));
// 		else if (last_node->content == min)
// 			rra(stack_a);
// 		else
// 			ra(stack_a);
// 	}
// 	sort_three(stack_a);
// 	pa(stack_b, stack_a);
// 	pa(stack_b, stack_a);
// }

// static void	sort_above_five(t_list **stack_a, t_list **stack_b)
// {
// 	int		pivot;
// 	int		size;
// 	int		max;
// 	int		i;
// 	t_list	*cheapest_node;

// 	max = ft_lstmax(*stack_a);
// 	size = ft_lstsize(*stack_a);
// 	i = 0;
// 	while (i < 4)
// 	{
// 		pivot = (max * (i + 1)) / 5;
// 		cheapest_node = ft_lstset_chunk(*stack_a, pivot, size);
// 		ft_lstpush_chunk(stack_a, stack_b, cheapest_node, pivot);
// 		size--;
// 		if (stack_iter(*stack_a, stack_is_chunk))
// 			i++;
// 	}
// 	ft_printf(1, "stack_b: %l\n", *stack_b);
// 	ft_printf(1, "stack_a: %l\n", *stack_a);
// }

// static void	sort_above_five(t_list **stack_a, t_list **stack_b)
// {
// }

void	sort(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	// int	size;

	// if (stack_iter(*stack_a, stack_is_sorted))
	// 	exit_success(*stack_a, *stack_b);
	// size = ft_lstsize(*stack_a);
	// if (size == 2 && ((*stack_a)->content > (*stack_a)->next->content))
	// 	sa(stack_a);
	// else if (size == 3)
	// 	sort_three(stack_a);
	// else if (size <= 5)
	// 	sort_five(stack_a, stack_b);
	// // else if (size <= 100)
	// // 	sort_hundred(stack_a, stack_b);
	// if (stack_iter(*stack_a, stack_is_sorted))
	// 	exit_success(*stack_a, *stack_b);
}

// ./push_swap 35 50 11 49 36 100 78 34 88 56 15 24 84 40 13 69 66 74 53 79 5 23 61 75 96 17 39 48 97 70 55 62 3 57 86 99 98 92 65 47 94 8 14 76 42 6 2 89 27 38 4 95 91 58 44 80 18 12 52 16 32 67 68 83 30 19 71 63 59 72 77 46 9 81 7 28 90 60 25 64 85 54 51 73 21 22 43 1 82 93 87 29 37 33 20 31 41 45 26 10