/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 03:51:00 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 01:55:41 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

bool	ft_lstiter(t_stack *lst, bool (*f)(int, t_stack *))
{
	int		value;
	bool	continue_iter;

	if (!lst)
		return (false);
	while (lst)
	{
		value = lst->content;
		lst = lst->next;
		continue_iter = f(value, lst);
		if (!continue_iter)
			return (false);
	}
	return (true);
}
