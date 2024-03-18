/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:46:44 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 09:51:10 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstcreate(t_list **lst, char **split)
{
	int		index;
	t_list	*new_node;
	t_atoi	res;

	index = 0;
	while (split[index])
	{
		res = ft_atoi(split[index]);
		new_node = ft_lstnew(res.nbr, index);
		ft_lstadd_back(lst, new_node);
		index++;
	}
}
