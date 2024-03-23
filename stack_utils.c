/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 01:40:31 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_create(t_stack *stack_a, char *av)
{
	t_atoi	res;
	t_list	*list;
	t_list	*new_node;

	list = NULL;
	while (*av)
	{
		while (*av && ft_isspace(*av))
			av++;
		if (!*av)
			break ;
		res = ft_atoi(av);
		if (res.error)
			exit_error(stack_a, NULL);
		new_node = ft_lstnew(res.nbr);
		if (!new_node)
			exit_error(stack_a, NULL);
		if (!stack_a->head)
			stack_a->head = new_node;
		ft_lstadd_back(&list, new_node);
		while (*av && !ft_isspace(*av))
			av++;
	}
	stack_a->last = new_node;
}

bool	stack_is_not_duplicated(int content, t_list *next_node)
{
	if (!next_node)
		return (true);
	if (content == next_node->content)
		return (false);
	return (stack_is_not_duplicated(content, next_node->next));
}

bool	stack_is_sorted(int content, t_list *next_node)
{
	if (!next_node)
		return (true);
	if (content > next_node->content)
		return (false);
	return (true);
}

bool	stack_is_chunk(int content, t_list *next_node)
{
	if (!next_node)
		return (true);
	if (content <= next_node->pivot)
		return (false);
	return (stack_is_chunk(next_node->content, next_node->next));
}

/*
	* void	stack_create(t_stack *stack, char *av)
		while (*av && *av == ' ')
			keep incrementing the av until we reach a char that's not a space

		- We don't need to check here if the av is empty or not or 
			any other validation cases, cuz at this point for sure we have
			a valid av, so we proceed with out logic.

	* bool	stack_is_not_duplicated(int content, t_list *next_node)
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
