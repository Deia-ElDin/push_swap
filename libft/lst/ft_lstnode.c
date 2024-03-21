/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:07:07 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 00:50:42 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_stack	*ft_lstnode(t_stack *lst, int index)
{
	while (lst && index--)
		lst = lst->next;
	return (lst);
}
