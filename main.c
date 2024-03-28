/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/25 11:52:20 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->last = NULL;
	stack->size = 0;
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	av++;
	init_stack(&a);
	init_stack(&b);
	parsing(av, &a);
	sort(&a, &b);
	return (0);
}

// make file -> clean & fclean

// test this case ./push_swap "1 2 3 "" " ,  ./push_swap "1 2 3 ""1"