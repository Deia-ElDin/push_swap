/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:46:44 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 02:06:16 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstcreate(t_stack **lst, char **split, void (*f)())
{
	t_stack	*new_node;
	t_atoi	res;
	int		index;
	int		value;

	index = 0;
	while (split[index])
	{
		res = ft_atoi(split[index]);
		value = (int)(res.nbr * res.sign);
		if (res.sign)
			value = (int)(res.nbr * res.sign);
		else
			value = (int)res.nbr;
		new_node = ft_lstnew(value, index);
		if (!new_node)
			f();
		ft_lstadd_back(lst, new_node);
		index++;
	}
}
