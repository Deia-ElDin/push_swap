/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 03:57:58 by dehamad          ###   ########.fr       */
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
void	parsing(char **av, t_stack *stack_a);

// Sort
void	sort(t_stack *stack_a, t_stack *stack_b);

// Stack Moves
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Stack Validation Utils
void	stack_map(t_stack *stack, char **av, void (*f)(t_stack*, char*));
bool	stack_iter(t_stack *stack, bool (*f)(int, t_list *));
void	stack_create(t_stack *stack_a, char *av);
bool	stack_is_not_duplicated(int value, t_list *next_node);
bool	stack_is_sorted(int value, t_list *next_node);
// bool	stack_is_chunk(int value, t_list *next_node);

// Sort Utils
void	push_and_sort(t_stack *from, t_stack *to, int *max_three);
// void	push_and_sort_b(t_stack *from, t_stack *to);
// Utils
void	avs_iter(char **av, void (*f)(char*));
void	exit_error(t_stack *stack_a, t_stack *stack_b);
void	exit_success(t_stack *stack_a, t_stack *stack_b);


#endif

// void	sort(t_list *a, t_list *b);
// void	sort_three(t_list *a);
// void	sort_five(t_list *a, t_list *b);
// void	sort_hundred(t_list *a, t_list *b);
// void	sort_five_hundred(t_list *a, t_list *b);
