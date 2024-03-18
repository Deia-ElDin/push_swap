/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:23:51 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 07:24:31 by dehamad          ###   ########.fr       */
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

int	is_sign_afterwords(char *av, int i)
{
	return (is_notnull(av, i) && ft_isdigit(av[i]) && is_sign(av[i + 1]));
}
