/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 03:21:16 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:02:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst);
}

/*
	malloc the content if the del fn is free.
	ex:
		1) t_list *node1 = malloc(sizeof(t_list));
				node1->content = malloc(sizeof(int));
				*(int *)node1->content = 42;
		2) t_list *node1 = malloc(sizeof(t_list));
				node1->content = malloc(sizeof(char));
				*(char *)node1->content = 'A';
		3) t_list *node1 = malloc(sizeof(t_list));
				node1->content = ft_strdup("abc");
*/
