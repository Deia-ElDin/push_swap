/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:15:22 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 06:44:38 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_pflist(t_fmt *fmt)
{
	t_list	*lst;

	lst = va_arg(fmt->args, t_list *);
	while (lst)
	{
		ft_putnbr_fd(lst->content, fmt->fd);
		lst = lst->next;
		if (lst)
			ft_putstr_fd(" -> ", fmt->fd);
	}
}
