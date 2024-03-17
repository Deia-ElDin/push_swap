/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:58:06 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/17 17:22:38 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "num.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((*str == '-' && --sign) || (*str == '+' && ++sign))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (nbr < 0 && sign < 0)
			return (0);
		if (nbr < 0 && sign >= 0)
			return (-1);
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	if (sign)
		return (nbr * sign);
	else
		return (nbr);
}
