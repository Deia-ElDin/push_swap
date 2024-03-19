/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 10:46:50 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_2(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

static void	sort_3(t_stack **stack_a)
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
	sort_2(stack_a);
}

static void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	t_stack	*last_node;

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
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (ft_lstiter(*stack_a, stack_is_sorted))
		exit_success(*stack_a, *stack_b);
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	if (ft_lstiter(*stack_a, stack_is_sorted))
		exit_success(*stack_a, *stack_b);
	// else if (size <= 100)
	// 	sort_hundred(stack_a, stack_b);
	// else
	// 	sort_5_hundred(stack_a, stack_b);
}
