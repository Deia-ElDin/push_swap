/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 02:46:49 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 02:16:13 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!lst || !new)
		return ;
	last_node = ft_lstlast(*lst);
	if (last_node)
	{
		new->prev = last_node;
		last_node->next = new;
	}
	else
		*lst = new;
}
