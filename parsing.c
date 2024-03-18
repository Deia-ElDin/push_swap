/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:22:42 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 10:44:19 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_empty(char *av)
{
	int	is_valid;
	int	i;

	i = 0;
	is_valid = 0;
	while (av[i])
	{
		if (av[i] != ' ' && ++is_valid)
			break ;
		i++;
	}
	if (!is_valid)
		exit_error();
}

static void	is_invalid_char(char *av)
{
	int	i;
	int	sign;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && av[i] != ' ' && av[i] != '-' && av[i] != '+')
			exit_error();
		i++;
	}
	i = 0;
	sign = 0;
	while (av[i])
	{
		if (av[i] && (is_multi_signs(av, i) || is_sign_afterwords(av, i)))
			exit_error();
		else if (av[i] == ' ' && sign > 0)
			sign = 0;
		i++;
	}
}

static void	is_int(char *av)
{
	int		i;
	int		j;
	t_atoi	res;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i] && av[i] == ' ')
			i++;
		j = i;
		while (av[j] && av[j] != ' ')
			j++; 
		if (j > i)
		{
			res = ft_atoi(av + i);
			if (res.error)
				exit_error();
		}
		i = j;
	}
}

// 2147483647, -2147483648

bool	parsing(int ac, char **av)
{
	char	*avs_str;
	char	**split;
	// t_list	*stack_a;
	// t_list	*stack_b;

	avs_iter(av, is_empty);
	avs_iter(av, is_invalid_char);
	avs_iter(av, is_int);
	avs_map(ac, av, &avs_str);
	split = ft_split(avs_str, ' ');
	ft_free(&avs_str, 'p');
	ft_printf(1, "split: %a\n", split);
	// is_int(split);
	// stack_a = NULL;
	// ft_lstcreate(&stack_a, split);
	// ft_free(&split, 'a');
	// ft_printf(1, "stack_a: %l\n", stack_a);
	// ft_lstclear(&stack_a);
	return (true);
}

//  ./push_swap "-2147483648" "2147483647"

/*
	The main idea is to create a validation functions for each step of the 
	parsing & pass it to avs_iter function to iterate over the avs.

	static void	is_empty(char *av)
		if (av[i] != ' ' && ++is_valid)
			if any char is not a space, then it's valid
		else
			if we exit the while with !is_valid => exit_error();		
*/