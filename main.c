/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 19:53:30 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac <= 1)
		return (0);
	av++;
	stack_a.head = NULL;
	stack_a.last = NULL;
	stack_a.size = 0;
	stack_b.head = NULL;
	stack_b.last = NULL;
	stack_a.size = 0;
	parsing(av, &stack_a);
	sort(&stack_a, &stack_b);
	return (0);
}

// make file -> clean & fclean

// test this case ./push_swap "1 2 3 "" " ,  ./push_swap "1 2 3 ""1"