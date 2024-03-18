/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:31:58 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 23:33:28 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	avs_iter(char **av, void (*f)(char*))
{
	unsigned int	i;

	i = 0;
	while (av[i])
		f(av[i++]);
}

char	*avs_map(char **av, char *(*f)(const char*, const char*))
{
	const char	*avs_str;
	const char	*tmp;

	avs_str = NULL;
	tmp = NULL;
	while (*av)
	{
		tmp = f(avs_str, *av);
		if (!tmp)
			exit_error();
		ft_free(&avs_str, 'p');
		avs_str = f(tmp, " ");
		if (!avs_str)
			exit_error();
		ft_free(&tmp, 'p');
		av++;
	}
	return ((char *)avs_str);
}

void	exit_error(void)
{
	ft_printf(2, "%s", "Error\n");
	exit(EXIT_FAILURE);
}


// char	*avs_map(int ac, char **av, char **avs_str)
// {
// 	size_t	len;
// 	char	*tmp;

// 	len = 0;
// 	while (*av)
// 		len += ft_strlen(*av++);
// 	av -= (ac - 1);
// 	*avs_str = (char *)ft_calloc(ac + len - 1, sizeof(char));
// 	if (!*avs_str)
// 		return (exit_error(), NULL);
// 	tmp = *avs_str;
// 	while (*av)
// 	{
// 		len = ft_strlen(*av);
// 		ft_strlcpy(tmp, *av, len + 1);
// 		tmp += len;
// 		if (!*(av + 1))
// 			break ;
// 		*tmp = ' ';
// 		tmp++;
// 		av++;
// 	}
// 	return (*avs_str);
// }