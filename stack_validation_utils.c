/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 10:48:43 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_is_duplicated(int value, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (value == next_node->content)
		return (false);
	return (stack_is_duplicated(value, next_node->next));
}

bool	stack_is_sorted(int value, t_stack *next_node)
{
	if (!next_node)
		return (true);
	if (value > next_node->content)
		return (false);
	return (true);
}
