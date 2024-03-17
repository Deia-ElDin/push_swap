/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:40:18 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/17 22:07:09 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strjoin_multi(int total, ...)
{
	va_list		args;
	size_t		total_len;
	char		*tmp;
	char		*result;
	int			i;

	va_start(args, total);
	i = -1;
	total_len = 0;
	while (++i < total)
		total_len += ft_strlen(va_arg(args, const char *));
	result = (char *)ft_calloc(total_len + 1, sizeof(char));
	if (!result)
		return (va_end(args), NULL);
	i = -1;
	while (++i < total)
	{
		tmp = ft_strjoin(result, va_arg(args, const char *));
		if (!tmp)
			return (va_end(args), ft_free(&result, 'p'), NULL);
		ft_free(&result, 'p');
		result = tmp;
	}
	va_end(args);
	return (result);
}
