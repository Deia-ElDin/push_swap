/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:11:52 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 22:20:02 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

int	*ft_lstmax_three(t_list *list)
{
	int		*max_three;

	max_three = (int *)malloc(3 * sizeof(int));
	if (max_three == NULL)
		return (NULL);
	max_three[0] = INT_MIN;
	max_three[1] = INT_MIN;
	max_three[2] = INT_MIN;
	while (list)
	{
		if (list->content > max_three[0])
		{
			max_three[2] = max_three[1];
			max_three[1] = max_three[0];
			max_three[0] = list->content;
		}
		else if (list->content > max_three[1])
		{
			max_three[2] = max_three[1];
			max_three[1] = list->content;
		}
		else if (list->content > max_three[2])
			max_three[2] = list->content;
		list = list->next;
	}
	return (max_three);
}
