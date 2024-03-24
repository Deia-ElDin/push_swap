/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:22:42 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 04:28:12 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_empty(char *av)
{
	int	i;
	int	is_valid;

	i = -1;
	is_valid = 0;
	while (av[++i])
		if (av[i] != ' ' && ++is_valid)
			break ;
	if (!is_valid)
		exit_error(NULL, NULL);
}

static void	is_invalid_user_input(char *av)
{
	unsigned int	i;

	i = 0;
	while (av[i])
	{
		if (!(av[i] == ' ' || ft_issign(av[i]) || ft_isdigit(av[i])))
			exit_error(NULL, NULL);
		if (ft_issign(av[i]) && !ft_isdigit(av[i + 1]))
			exit_error(NULL, NULL);
		if (ft_isdigit(av[i]) && ft_issign(av[i + 1]))
			exit_error(NULL, NULL);
		i++;
	}
}

void	parsing(char **av, t_stack *stack_a)
{
	avs_iter(av, is_empty);
	avs_iter(av, is_invalid_user_input);
	stack_map(stack_a, av, stack_create);
	if (!stack_iter(stack_a, stack_is_not_duplicated))
		exit_error(stack_a, NULL);
}

/*
	*The main idea here is to go as far as possible in the parsing WITHOUT MALLOC
	*The way we do it is by creating a validation functions for each step of the
	*parsing & pass it to avs_iter function to iterate over the avs.

	* static void	is_empty(char *av)
		if (av[i] != ' ' && ++is_valid)
			if any char is not a space, then it's valid
		else
			if we exit the while with !is_valid => exit_error(NULL, NULL);

	* static void	is_invalid_char(char *av)
		doest 2 things:
			1- check if there's any char which is not among (0-9, ' ', '-', '+')
			2- check if there's invalid sign case i.e (--, -+, 1-, -1-, - )
*/
