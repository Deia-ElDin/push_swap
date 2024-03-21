/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:15:22 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 06:34:34 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_pflist(t_fmt *fmt)
{
	t_stack	*lst;

	lst = va_arg(fmt->args, t_stack *);
	while (lst)
	{
		// ft_putstr_fd("\nIndex: ", fmt->fd);
		// ft_putnbr_fd(lst->index, fmt->fd);
		ft_putchar_fd('\n', fmt->fd);
		ft_putstr_fd("Content: ", fmt->fd);
		ft_putnbr_fd(lst->content, fmt->fd);
		ft_putchar_fd('\n', fmt->fd);
		ft_putstr_fd("Moves: ", fmt->fd);
		ft_putnbr_fd(lst->moves, fmt->fd);
		ft_putchar_fd('\n', fmt->fd);
		lst = lst->next;	
	}
}
