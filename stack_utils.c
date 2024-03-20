/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 00:46:34 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_map(t_stack **stack, char **av, void (*f)(t_stack**, char*))
{
	unsigned int	i;

	i = 0;
	while (av[i])
		f(stack, av[i++]);
}

bool	stack_iter(t_stack *stack, bool (*f)(int, t_stack *))
{
	int		value;
	bool	continue_iter;

	if (!stack)
		return (false);
	while (stack)
	{
		value = stack->content;
		stack = stack->next;
		continue_iter = f(value, stack);
		if (!continue_iter)
			return (false);
	}
	return (true);
}

void	stack_create(t_stack **stack_a, char *av)
{
	unsigned int	i;
	t_atoi			res;
	t_stack			*new_node;

	i = 0;
	while (av[i])
	{
		while (av[i] && ft_isspace(av[i]))
			i++;
		res = ft_atoi(av + i);
		if (res.error)
			exit_error(*stack_a, NULL);
		new_node = ft_lstnew(res.nbr, 0);
		if (!new_node)
			exit_error(*stack_a, NULL);
		ft_lstadd_back(stack_a, new_node);
		while (av[i] && !ft_isspace(av[i]))
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

/*
	* void	stack_map(t_stack **stack, char **av, void (*f)(t_stack**, char*))
		- The purpose of this fn is to return a ptr just like strmapi, 
			but instead of we return the ptr, we took a double ptr.
		- We are iterating over the avs and apply's (stack_create) to each av.
		- We used this method instead of spliting then free,
			then we will malloc any way for the stack.
	
	* bool	stack_iter(t_stack *stack, bool (*f)(int, t_stack *))
		if (!stack)
			incase by mistake we passed a stack and it's empty or null
			we don't want to return true, cuz if we do, most likely in our code
			we will exit failure which in this case it's wrong.

	* void	stack_create(t_stack **stack_a, char *av)
		while (av[i] && av[i] == ' ')
			keep incrementing i until we reach a char that's not a space

		- We don't need to check here if the av is empty or not or 
			any other validation cases, cuz at this point for sure we have
			a valid av, so we proceed with out logic.
*/
