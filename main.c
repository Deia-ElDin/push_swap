/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 01:16:08 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac <= 1)
		return (0);
	av++;
	stack_a = NULL;
	stack_b = NULL;
	parsing(av, &stack_a);
	// ft_printf(1, "stack_a: %l\n", stack_a);
	sort(&stack_a, &stack_b);
	return (0);
}

// make file -> clean & fclean

// test this case ./push_swap "1 2 3 "" " ,  ./push_swap "1 2 3 ""1"