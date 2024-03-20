/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:22:42 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/20 23:55:33 by dehamad          ###   ########.fr       */
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

static void	is_invalid_char(char *av)
{
	int	i;

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

void	parsing(char **av, t_stack **stack_a)
{
	avs_iter(av, is_empty);
	avs_iter(av, is_invalid_char);
	stack_map(stack_a, av, stack_create);
	if (!stack_iter(*stack_a, stack_is_duplicated))
		exit_error(*stack_a, NULL);
}

// 2147483647, -2147483648

/*
	*The main idea here is to go as far as possible in the parsing WITHOUT MALLOC
	*The way we do it is by creating a validation functions for each step of the,
	*parsing & pass it to avs_iter function to iterate over the avs.

	* static void	is_empty(char *av)
		if (av[i] != ' ' && ++is_valid)
			if any char is not a space, then it's valid
		else
			if we exit the while with !is_valid => exit_error(NULL, NULL);

	* static void	is_invalid_char(char *av)
		doest 2 things:
			1- check if there's any char which is not among (0-9, ' ', '-', '+')
			2- check if there's invalid sign case i.e (--, -+, 1-, -1-)

		while (av[i])
		{
			if (av[i] && (is_multi_signs(av, i) || is_sign_after_digit(av, i)))
				is_multi_signs i.e (--, -+)
				is_sign_after_digit i.e (1-, -1-)
			else if (av[i] == ' ' && sign > 0)
				once we find a space we reset the sign to 0
			i++;
		}

	* static void	is_int(char *av)
		while (av[i] && av[i] == ' ')
			as long as it's a whitespace, keep moving.

		j = i;
		after this while loop, either we are at the \0 or at the first 
		digit of the first number, so we set the j = i, and we proceed with the j
		for 2 reasons:
			1- if j is different from i, then we have a number
			2- we won't lose our start point which is av[i]

		if (j > i)
		{
			res = ft_atoi(av + i);
				note that our atoi handles cases such as ( - ), ( + ), ( -+ )
			if (res.error)
				exit_error(NULL, NULL);
		}

		i = j;
		at the end we set i to j, so we can continue from where we left off.
*/
