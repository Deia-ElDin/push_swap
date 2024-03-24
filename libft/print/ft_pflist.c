/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pflist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:15:22 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 04:36:51 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_pflist(t_fmt *fmt)
{
	t_list	*lst;

	lst = va_arg(fmt->args, t_list *);
	while (lst)
	{
		if (lst->target)
			printf("Index: %d, Content: %d, Target = %d, Moves = %d, Cheapest = %d\n",
				lst->index, lst->content, lst->target->content, lst->moves, lst->cheapest);
		else
			printf("Index: %d, Content: %d, Moves = %d, Cheapest = %d\n",
				lst->index, lst->content, lst->moves, lst->cheapest);
		lst = lst->next;
	}
}

	// ft_putstr_fd("\nIndex: ", fmt->fd);
		// ft_putnbr_fd(lst->index, fmt->fd);
		// ft_putchar_fd('\n', fmt->fd);
		// ft_putstr_fd("Content: ", fmt->fd);
		// ft_putnbr_fd(lst->content, fmt->fd);
		// ft_putchar_fd('\n', fmt->fd);
		// ft_putstr_fd("Target: ", fmt->fd);
		// ft_putnbr_fd(lst->target, fmt->fd);
		// ft_putchar_fd('\n', fmt->fd);
		// printf("Index: %d\n", lst->index);
				// printf("Target: %d\n", lst->target);
		// printf("Moves: %d\n", lst->moves);
		// printf("Cheapest: %d\n\n", lst->cheapest);
			// if (lst)
		// 	ft_putstr_fd(" -> ", fmt->fd);
		// else
		// 	ft_putchar_fd('\n', fmt->fd);