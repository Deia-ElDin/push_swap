/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:23:51 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 23:25:41 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sign(int c)
{
	return (c == '-' || c == '+');
}

static int	is_notnull(char *av, int i)
{
	return (av[i] && av[i + 1]);
}

int	is_multi_signs(char *av, int i)
{
	return (is_notnull(av, i) && is_sign(av[i]) && is_sign(av[i + 1]));
}

int	is_sign_after_digit(char *av, int i)
{
	return (is_notnull(av, i) && ft_isdigit(av[i]) && is_sign(av[i + 1]));
}

int	is_invalid_after_sign(char *av, int i)
{
	return (is_notnull(av, i) && is_sign(av[i]) && !ft_isdigit(av[i + 1]));
}

/*
	* static int	is_notnull(char *av, int i)
		we are checking if the current and next characters are not null

	* int	is_multi_signs(char *av, int i)
		we are checking if the current and next characters are signs
		i.e. (--, -+, ++, +-, ...)

	* int	is_sign_after_digit(char *av, int i)
		we are checking if the current character is a digit 
		and the next character is a sign
		i.e. (1-, 1+, 2-, 2+, ...)

	* int	is_invalid_after_sign(char *av, int i)
		we are checking if the current character is a sign 
		and the next character is not a digit
		i.e. (- , + , ...)
*/