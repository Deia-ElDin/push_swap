/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:49:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:26:03 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->index = 0;
	new_node->moves = 0;
	new_node->pivot = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/*
  void *content
    A void * is a generic pointer type that can hold the address
	of any data type. It is often used for generic functions
	or data structures where the type of the data is not known beforehand.

  sizeof(t_list)
    - The sizeof(t_list) is related to the size of the structure itself,
		not the size of the content it points to.
    - If you store an int in the content member,
		the sizeof(int) bytes of data will be somewhere in memory,
		and the content member will store the address of that memory location.
		The sizeof(t_list) remains the same because the size of a pointer
		is the same, regardless of what it points to.
    - If you store a char * in the content member, 
		the sizeof(char *) bytes (typically the size of a pointer on
      	your system) of the pointer will be stored in the content member.
		Again, the sizeof(t_list) remains the same.
*/
