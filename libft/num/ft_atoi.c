/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:58:06 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 01:37:40 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

t_atoi	ft_atoi(const char *str)
{
	t_atoi	res;
	int		sign;

	res.nbr = 0;
	res.error = false;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' && ++str)
		sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		res.nbr = (res.nbr * 10) + (*str - '0');
		if (res.nbr > INT_MAX && sign > 0)
			return (res.error = true, res.nbr = 0, res);
		if (res.nbr * sign < INT_MIN && sign < 0)
			return (res.error = true, res.nbr = 0, res);
		str++;
	}
	return (res);
}

/*
	* This atoi DOESN'T mimic the real atoi
		- To do so we need to add these 2 checks instead of the current 2,
			and set the nbr back to int type.
			if (res.nbr < 0 && res.sign < 0)
				return (res.error = true, res.nbr = 0, res);
			if (res.nbr < 0 && res.sign >= 0)
				return (res.error = true, res.nbr = -1, res);
*/
