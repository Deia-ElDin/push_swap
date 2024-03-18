/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 03:51:00 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 12:01:53 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstiter(t_list *lst, void (*f)(int, t_list *))
{
	int	value;

	if (!lst)
		return ;
	while (lst)
	{
		value = lst->content;
		f(value, lst->next);
		lst = lst->next;
	}
}
