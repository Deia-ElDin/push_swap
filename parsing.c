/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:22:42 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 12:26:33 by dehamad          ###   ########.fr       */
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
			printf("res.nbr: %ld\n", res.nbr);
			printf("res.sign: %d\n", res.sign);
			printf("res.error: %d\n", res.error);
			if (res.error)
				exit_error();
		}
		i = j;
	}
}

static void	is_dup(int value, t_list *next_node)
{
	if (!next_node)
		return ;
	if (value == next_node->content)
		exit_error();
	if (next_node->next)
		is_dup(value, next_node->next);
}


bool	parsing(int ac, char **av)
{
	char	*avs_str;
	char	**split;
	t_list	*stack_a;
	// t_list	*stack_b;

	avs_iter(av, is_empty);
	avs_iter(av, is_invalid_char);
	avs_iter(av, is_int);
	avs_map(ac, av, &avs_str);
	split = ft_split(avs_str, ' ');
	ft_free(&avs_str, 'p');
	stack_a = NULL;
	ft_lstcreate(&stack_a, split);
	ft_lstiter(stack_a, is_dup);
	ft_free(&split, 'a');
	ft_lstclear(&stack_a);
	return (true);
}

//  ./push_swap "-2147483648" "2147483647"

/*
	*The main idea here is to go as far as possible in the parsing WITHOUT MALLOC
	*The way we do it is by creating a validation functions for each step of the,
	*parsing & pass it to avs_iter function to iterate over the avs.

	* static void	is_empty(char *av)
		if (av[i] != ' ' && ++is_valid)
			if any char is not a space, then it's valid
		else
			if we exit the while with !is_valid => exit_error();

	* static void	is_invalid_char(char *av)
		doest 2 things:
			1- check if there's any char which is not among (0-9, ' ', '-', '+')
			2- check if there's invalid sign case i.e (--, -+, 1-, -1-)

		while (av[i])
		{
			if (av[i] && (is_multi_signs(av, i) || is_sign_afterwords(av, i)))
				is_multi_signs i.e (--, -+)
				is_sign_afterwords i.e (1-, -1-)
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
				exit_error();
		}

		i = j;
		at the end we set i to j, so we can continue from where we left off.
*/
