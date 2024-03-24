/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 05:26:45 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_create(t_stack *a, char *av)
{
	t_atoi	res;
	t_list	*new_node;

	while (*av)
	{
		while (*av && ft_isspace(*av))
			av++;
		if (!*av)
			break ;
		res = ft_atoi(av);
		if (res.error)
			exit_error(a, NULL);
		new_node = ft_lstnew(res.nbr);
		if (!new_node)
			exit_error(a, NULL);
		if (!a->head)
			a->head = new_node;
		ft_lstadd_back(&(a->head), new_node, a->last);
		a->size++;
		a->last = new_node;
		while (*av && !ft_isspace(*av))
			av++;
	}
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

/*
	* void	create(t_stack *stack, char *av)
		while (*av && *av == ' ')
			keep incrementing the av until we reach a char that's not a space

		- We don't need to check here if the av is empty or not or 
			any other validation cases, cuz at this point for sure we have
			a valid av, so we proceed with out logic.

	* bool	is_not_duplicated(int content, t_list *next_node)
		if (!next_node)
			return (true);
			- If we reach the end of the stack, this means we didn't find
				any duplicate, so we return true.

		if (content == next_node->content)
			return (false);
			- If we found a duplicate, we return false,
				so we stop the iteration and we return false, 
				in our parsing we check:
					if (!iter(*a, is_not_duplicated))
						exit_error(*a, NULL);
*/
