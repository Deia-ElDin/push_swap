/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:51:22 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 01:55:41 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int	ft_lstsize(t_stack *lst)
{
	int	len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}
