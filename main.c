/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/17 23:03:02 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	bool	is_valid_av;


	if (ac <= 1)
		return (0);
	is_valid_av = parsing(ac, av);
	printf("is_valid_av: %d\n", is_valid_av);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	size_t		len; 
// 	int				spaces;
// 	char 			*final_str;
// 	char 			*tmp;

// 	len = 0;
// 	spaces = 0;
// 	if (ac <= 1)
// 		return (0);
// 	while (*(++av))
// 		len += ft_strlen(*av);
// 	printf("ac: %d\n", ac);
// 	av -= (ac);
// 	final_str = ft_calloc(len + ac + 1, sizeof(char));
// 	tmp = final_str;
// 	while (*(++av))
// 	{
// 		len = ft_strlen(*av);
// 		ft_strlcpy(tmp, *av, len + 1);
// 		tmp += len;
// 		*tmp = ' ';
// 		tmp++;
// 	}
// 	printf("final_str => final: %s\n", final_str);
// 	return (0);
// }

/*
	strlen for each av without the spaces
	count_Words


		// len = ft_strlen(nbr);
	// if (len < 10) 
	// 	printf("Valid Integer\n");
	// while (*nbr == '0')
	// 	nbr++;
	// printf("result: %d\n", ft_strcmp(nbr, "2147483647"));
*/


// static int	len_without_whitespaces(char *nbr)
// {
// 	int	len;

// 	len = 0;
// 	while (*nbr)
// 	{

// 		if (!ft_isspace(*nbr) && ft_isascii(*nbr))
// 			len++;
// 		nbr++;
// 	}
// 	return (len);
// }

// static int	count_words(char const *av)
// {
// 	int	words;
// 	int	i;

// 	words = 0;
// 	i = 0;
// 	while (av[i])
// 	{
// 		if (av[i] && !ft_isspace(av[i]))
// 		{
// 			words++;
// 			while (av[i] && !ft_isspace(av[i]))
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (words);
// }


//  "+1 -2 45 54" "5                 3" "8"
// "1 2 3" "45 6"