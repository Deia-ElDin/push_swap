/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:22:42 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/17 23:01:52 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_avs_total_length(int ac, const char **av)
{
	size_t  len;

	len = 0;
	while (*(++av))
		len += ft_strlen(*av);
	return (len);
}

char	*build_final_str(int ac, const char **av, size_t len)
{
	char	*final_str;
	char	*tmp;

	final_str = (char *)malloc(ac + len - 2);
	if (!final_str)
		return (NULL);
	tmp = final_str;
	while (*(++av))
	{
		len = ft_strlen(*av);
		ft_strlcpy(tmp, *av, len + 1);
		tmp += len;
		if (*(av + 1))
		{
			*tmp = ' ';
			tmp++;
		}
	}
	return (final_str);
}

bool	parsing(int ac, char **av)
{
	size_t	total_length;
	char	*final_str;

	if (ac <= 1)
		return (false);
	// total_length = get_avs_total_length(ac, (const char **)av);
	// final_str = build_final_str(ac, (const char **)av, total_length);
	final_str = ft_strjoin_multi(ac - 1, av);
	printf("final_str => final: %s\n", final_str);
	return (true);
}