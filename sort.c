/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 08:13:30 by dehamad          ###   ########.fr       */
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
	int		pivot;
	int		size;
	int		max;
	int		i;
	t_chunk	chunk;

	max = ft_lstmax(*stack_a);
	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < 4)
	{
		pivot = (max * (i + 1)) / 5;
		ft_lstchunk(&chunk, *stack_a, pivot, size);
		while (chunk.cheapest && chunk.cheapest->moves)
		{
			if (chunk.cheapest->moves > 0 && chunk.cheapest->moves--)
				ra(stack_a);
			else if (chunk.cheapest->moves < 0 && chunk.cheapest->moves++)
				rra(stack_a);
		}
		if (!chunk.cheapest->moves && chunk.cheapest->content <= pivot)
			pb(stack_a, stack_b);
		size--;
		if (stack_iter(*stack_a, stack_is_chunk))
			i ++;
	}
	// ft_printf(1, "stack_b: %l\n", *stack_b);
	// ft_printf(1, "stack_a: %l\n", *stack_a);
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
}

// ./push_swap 83 97 54 13 44 82 19 77 23 91 15 68 62 34 6 49 1 70 25 81 28 10 29 88 51 73 14 87 58 16 80 98 42 100 20 17 84 27 76 93 50 61 43 22 2 45 48 39 36 72 3 47 85 40 71 79 86 24 37 53 95 41 69 38 63 8 26 9 7 12 78 31 74 5 66 67 65 32 33 89 55 64  


	// ft_printf(1, "stack_a: %l\n", *stack_a);
	// ft_printf(1, "stack_b: %l\n", *stack_b);

	// printf("chunk content: %d\n", chunk.cheapest->content);
	// printf("chunk moves: %d\n", chunk.cheapest->moves);
	// printf("chunk len: %d\n", chunk.len);
	// printf("pivots[i]: %d\n", pivots[i]);
	// printf("stack_iter(*stack_a, stack_is_chunk) = %d\n", stack_iter(*stack_a, stack_is_chunk));

	// i = -1;
	// while (++i < 5)
	// 	pivots[i] = (max * (i + 1)) / 5;