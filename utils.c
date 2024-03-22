/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:31:58 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 23:36:12 by dehamad          ###   ########.fr       */
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

	if (!stack || !stack->head)
		return (false);
	lst = stack->head;
	while (lst)
	{
		content = lst->content;
		lst = lst->next;
		continue_iter = f(content, lst);
		if (!continue_iter)
			return (false);
	}
	return (true);
}

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		ft_lstclear(&(stack_a->head));
	if (stack_b)
		ft_lstclear(&(stack_b->head));
	ft_printf(2, "%s", "Error\n");
	exit(EXIT_FAILURE);
}

void	exit_success(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		ft_lstclear(&(stack_a->head));
	if (stack_b)
		ft_lstclear(&(stack_b->head));
	exit(EXIT_SUCCESS);
}

void	print_int_arr(int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("i = %d, value = %d\n", i, arr[i]);
}

/*
	* void	stack_map(t_list **stack, char **av, void (*f)(t_list**, char*))
		- The purpose of this fn is to return a ptr just like strmapi, 
			but instead of we return the ptr, we took a double ptr.
		- We are iterating over the avs and apply's (stack_create) to each av.
		- We used this method instead of spliting then free,
			then we will malloc any way for the stack.
	
	* bool	stack_iter(t_list *stack, bool (*f)(int, t_list *))
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
*/
