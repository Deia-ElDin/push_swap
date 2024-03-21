/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 07:58:53 by dehamad          ###   ########.fr       */
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
	int		content;
	bool	continue_iter;

	if (!stack)
		return (false);
	while (stack)
	{
		content = stack->content;
		stack = stack->next;
		continue_iter = f(content, stack);
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
		new_node = ft_lstnew(res.nbr);
		if (!new_node)
			exit_error(*stack_a, NULL);
		ft_lstadd_back(stack_a, new_node);
		while (av[i] && !ft_isspace(av[i]))
			i++;
	}
}

bool	stack_is_not_duplicated(int content, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (content == next_node->content)
		return (false);
	return (stack_is_not_duplicated(content, next_node->next));
}

bool	stack_is_sorted(int content, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (content > next_node->content)
		return (false);
	return (true);
}

bool	stack_is_chunk(int content, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (content <= next_node->pivot)
		return (false);
	return (stack_is_chunk(next_node->content, next_node->next));
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
			- Incase by mistake we passed a stack and it's empty or null
				we don't want to return true, cuz if we do, most likely in our 
				code we will exit failure which in this case it's wrong.

		if (!continue_iter)
			return (false);
			- If the function we passed to the stack_iter return false, 
				this means our whatever condition we are checking is not met,
				therefore we return false, and we act accordingly.
				i.e stack_is_not_duplicated if there's a duplicate we return
				false, so we stop the iteration and we return false, in our 
				parsing we check:
				if (!stack_iter(*stack_a, stack_is_not_duplicated))
					exit_error(*stack_a, NULL);
			
	* void	stack_create(t_stack **stack_a, char *av)
		while (av[i] && av[i] == ' ')
			keep incrementing i until we reach a char that's not a space

		- We don't need to check here if the av is empty or not or 
			any other validation cases, cuz at this point for sure we have
			a valid av, so we proceed with out logic.

	* bool	stack_is_not_duplicated(int content, t_stack *next_node)
		if (!next_node)
			return (true);
			- If we reach the end of the stack, this means we didn't find
				any duplicate, so we return true.

		if (content == next_node->content)
			return (false);
			- If we found a duplicate, we return false,
				so we stop the iteration and we return false, 
				in our parsing we check:
					if (!stack_iter(*stack_a, stack_is_not_duplicated))
						exit_error(*stack_a, NULL);
*/
