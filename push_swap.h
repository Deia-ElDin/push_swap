/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/28 10:27:06 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*head;
	t_list	*last;
	int		size;
}	t_stack;

// Parsing
void	parsing(char **av, t_stack *a);

// Sort
void	sort(t_stack *a, t_stack *b);

// Stack Moves
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Stack Validation Utils
void	stack_map(t_stack *stack, char **av, void (*f)(t_stack*, char*));
bool	stack_iter(t_stack *stack, bool (*f)(int, t_list *));
void	stack_create(t_stack *a, char *av);
bool	stack_is_not_duplicated(int value, t_list *next_node);
bool	stack_is_sorted(int value, t_list *next_node);

// Sort Utils
void	pb_and_sort_descending(t_stack *from, t_stack *to);
void	pa_and_sort_ascending(t_stack *a, t_stack *b);

// Utils
void	avs_iter(char **av, void (*f)(char*));
void	exit_error(t_stack *a, t_stack *b);
void	exit_success(t_stack *a, t_stack *b);

#endif

// void	sort(t_list *a, t_list *b);
// void	sort_three(t_list *a);
// void	sort_five(t_list *a, t_list *b);
// void	sort_hundred(t_list *a, t_list *b);
// void	sort_five_hundred(t_list *a, t_list *b);
