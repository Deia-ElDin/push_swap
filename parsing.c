/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:22:42 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 05:37:14 by dehamad          ###   ########.fr       */
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
	size_t	len;
	size_t	i;
	int		sign;

	len = ft_strlen(av) - 1;
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

bool	parsing(int ac, char **av)
{
	char	*avs_str;
	char	**split;
	t_list	*stack_a;
	t_list	*stack_b;


	avs_iter(av, is_empty);
	avs_iter(av, is_invalid_char);
	avs_map(ac, av, &avs_str);
	split = ft_split(avs_str, ' ');
	printf("final_str => final: %s\n", avs_str);
	ft_printf(1, "split: %a\n", split);
	return (true);
}
	// char	*final_str;

// final_str = build_final_str(ac, (const char **)av);
	// printf("final_str => final: %s\n", final_str);



// int	is_multi_signs(char *str)
// {
// 	int	signs;

// 	signs = 0;
// 	while (*str)
// 	{
// 		if (ft_strchr("+-*/", *str))
// 			signs++;
// 		if (*str == '-' || *str == '+')
// 			signs++;
// 		str++;
// 	}
// }

// bool	ft_isvalid_input(int index, char *str)
// {
// 	char	c;

// 	c = str[index];
// 	if (!index && str[index + 1])
// 	{
// 		if ((c == '-' || c == '+') && !ft_isdigit(str[index + 1]))
// 			return (false);
// 	}
// 	return (ft_isspace(c) || ft_isdigit(c) || c == '-' || c == '+');
// }

// bool	is_valid_char(int letter)
// {
// 	char	*valid;

// 	valid = " -+0123456789";
// 	return (ft_strchr(valid, letter) != NULL);
// }

// bool	is_multi_signs(char *str)
// {
// 	int	plus;
// 	int	minus;

// 	plus = 0;
// 	minus = 0;
// 	while (*str)
// 	{
// 		if (ft_strchr("+-*/", *str))
// 			signs++;
// 		if (*str == '-' || *str == '+')
// 			signs++;
// 		str++;
// 	}
// 	return (signs > 1);
// }

// static void	is_valid_int(char *av)
// {
// 	int		i;
// 	int		len;
// 	char	*tmp;

// 	i = 0;
// 	len = 0;
// 	tmp = av;
// 	while (*tmp)
// 	{
// 		if (ft_isdigit(*tmp))
// 			len++;
// 		tmp++;
// 	}
// 	if (len > 10)
// 		exit_error();
// 	if (len == 10 && ft_strcmp(av, "2147483647") > 0)
// 		exit_error();
// }