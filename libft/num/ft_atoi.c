/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:58:06 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 10:45:31 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

t_atoi	ft_atoi(const char *str)
{
	t_atoi	res;

	res.nbr = 0;
	res.sign = 0;
	res.error = false;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' && --res.sign) || (*str == '+' && ++res.sign))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (res.nbr < 0 && res.sign < 0)
			return (res.error = true, res.nbr = 0, res);
		if (res.nbr < 0 && res.sign >= 0)
			return (res.error = true, res.nbr = -1, res);
		res.nbr = (res.nbr * 10) + (*str - '0');
		if (res.nbr > INT_MAX && res.sign >= 0)
			return (res.error = true, res.nbr = 0, res);
		if (res.nbr * res.sign < INT_MIN && res.sign < 0)
			return (res.error = true, res.nbr = 0, res);
		str++;
	}
	if (!res.nbr && res.sign)
		return (res.error = true, res.nbr = 0, res);
	return (res);
}
