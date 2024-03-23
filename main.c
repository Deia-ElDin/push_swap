/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:27:56 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/23 02:02:47 by dehamad          ###   ########.fr       */
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
	stack_b.head = NULL;
	stack_b.last = NULL;
	parsing(av, &stack_a);
	ft_printf(1, "stack_a: %l\n", stack_a.head);
	sa(&stack_a);
	ft_printf(1, "stack_a head: %l\n", stack_a.head);
	ft_printf(1, "stack_a last content: %d\n", stack_a.last->content);
	sa(&stack_a);
	ft_printf(1, "stack_a head: %l\n", stack_a.head);
	ft_printf(1, "stack_a last content: %d\n", stack_a.last->content);
	// sa(&stack_a);
	// ft_printf(1, "stack_a head: %l\n", stack_a.head);
	// ft_printf(1, "stack_a last content: %d\n", stack_a.last->content);
	// ft_printf(1, "stack_b head: %l\n", stack_b.head);
	// ft_printf(1, "stack_b last content: %d\n", stack_b.last->content);
	// pb(&stack_a, &stack_b);
	// ft_printf(1, "stack_a head: %l\n", stack_a.head);
	// ft_printf(1, "stack_a last content: %d\n", stack_a.last->content);
	// ft_printf(1, "stack_b head: %l\n", stack_b.head);
	// ft_printf(1, "stack_b last content: %d\n", stack_b.last->content);
	// sort(&stack_a, &stack_b);
	// return (0);
}

// make file -> clean & fclean

// test this case ./push_swap "1 2 3 "" " ,  ./push_swap "1 2 3 ""1"