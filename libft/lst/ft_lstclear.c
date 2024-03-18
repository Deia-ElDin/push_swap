/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 03:33:15 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 07:46:41 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current_node;
	t_list	*next_node;

	if (!lst || !*lst)
		return ;
	current_node = *lst;
	while (current_node)
	{
		next_node = current_node->next;
		ft_lstdelone(current_node);
		current_node = next_node;
	}
	*lst = NULL;
}

/*
	if (!lst || !*lst)
		!lst: Checks if the pointer lst itself is a null pointer. 
			If lst is null, it means that the linked list is empty 
			(not pointing to any nodes).
		!*lst: Checks if the pointer that lst is pointing to is a null pointer.
			If *lst is null, it means that the linked list is not empty but
			the current node is null or the end of the list.

	The recursive way:
		ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
	but if we go that way we must add this condition
		if (!lst || !*lst)
			so once we reach the last call where *lst pointing to NULL;
			we return backward to handle our ft_lstdelone(*lst, del);
*/
