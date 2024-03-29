/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:31:58 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/25 00:50:03 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	avs_iter(char **av, void (*f)(char*))
{
	unsigned int	i;

	i = 0;
	while (av[i])
		f(av[i++]);
}

void	stack_map(t_stack *stack, char **av, void (*f)(t_stack*, char*))
{
	unsigned int	i;

	i = 0;
	while (av[i])
		f(stack, av[i++]);
}

bool	stack_iter(t_stack *stack, bool (*f)(int, t_list *))
{
	t_list	*lst;
	int		content;
	bool	continue_iter;

	lst = stack->head;
	while (lst)
	{
		content = lst->content;
		continue_iter = f(content, lst->next);
		if (!continue_iter)
			return (false);
		lst = lst->next;
	}
	return (true);
}

void	exit_error(t_stack *a, t_stack *b)
{
	if (a && a->head)
		ft_lstclear(&(a->head));
	if (b && b->head)
		ft_lstclear(&(b->head));
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_success(t_stack *a, t_stack *b)
{
	if (a && a->head)
		ft_lstclear(&(a->head));
	if (b && b->head)
		ft_lstclear(&(b->head));
	exit(EXIT_SUCCESS);
}

/*
	* void	map(t_stack *stack, char **av, void (*f)(t_stack*, char*))
		- The purpose of this fn is to return a ptr just like strmapi, 
			but instead of we return the ptr, we took a ptr to the stack.
		- We are iterating over the avs and apply's (create) to each av.
		- We used this method instead of spliting then free,
			then we will malloc any way for the stack.
	
	* bool	iter(t_stack *stack, bool (*f)(int, t_list *))
		if (!stack->head)
			- Incase by mistake we passed a stack and it's empty or null
				we don't want to return true, cuz if we do, most likely in our 
				code we will exit failure which in this case it's wrong.

		if (!continue_iter)
			return (false);
			- If the function we passed to the iter return false, 
				this means our whatever condition we are checking is not met,
				therefore we return false, and we act accordingly.
				i.e is_not_duplicated if there's a duplicate we return
				false, so we stop the iteration and we return false, in our 
				parsing we check:
				if (!iter(*a, is_not_duplicated))
					exit_error(*a, NULL);
*/
