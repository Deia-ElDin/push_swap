/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/20 21:51:05 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_create(t_stack **stack_a, char *av)
{
	unsigned int	i;
	t_atoi			res;
	t_stack			*new_node;

	i = 0;
	while (av[i])
	{
		while (av[i] && av[i] == ' ')
			i++;
		if (!(av[i] || av[i] == '-' || av[i] == '+' || ft_isdigit(av[i])))
			break ;
		res = ft_atoi(av + i);
		if (res.error)
			exit_error(*stack_a, NULL);
		if (res.sign)
			new_node = ft_lstnew((int)(res.nbr * res.sign), 0);
		else
			new_node = ft_lstnew((int)res.nbr, 0);
		if (!new_node)
			exit_error(*stack_a, NULL);
		ft_lstadd_back(stack_a, new_node);
		while (av[i] && av[i] != ' ')
			i++;
	}
}

bool	stack_is_duplicated(int value, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (value == next_node->content)
		return (false);
	return (stack_is_duplicated(value, next_node->next));
}

bool	stack_is_sorted(int value, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (value > next_node->content)
		return (false);
	return (true);
}

// bool	stack_is_sorted_chunk(t_stack **stack, t_stack *pivot)
// {
// 	while (*stack)
// 	{
// 		if ((*stack)->content < pivot->content)
// 			return (false);
// 		*stack = (*stack)->next;
// 	}
// }
