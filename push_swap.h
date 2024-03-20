/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/20 22:05:50 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Parsing
void	parsing(char **av, t_stack **stack_a);

// Sign Parsing Utils
int		is_multi_signs(char *av, int i);
int		is_sign_after_digit(char *av, int i);
int		is_invalid_after_sign(char *av, int i);

// Sort
void	sort(t_stack **stack_a, t_stack **stack_b);

// Stack Moves
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Stack Validation Utils
void	stack_map(t_stack **stack, char **av, void (*f)(t_stack**, char*));
bool	stack_iter(t_stack *stack, bool (*f)(int, t_stack *));
void	stack_create(t_stack **stack_a, char *av);
bool	stack_is_duplicated(int value, t_stack *next_node);
bool	stack_is_sorted(int value, t_stack *next_node);

// Utils
void	avs_iter(char **av, void (*f)(char*));
void	exit_error(t_stack *stack_a, t_stack *stack_b);
void	exit_success(t_stack *stack_a, t_stack *stack_b);
void	print_int_arr(int *arr);

#endif

// void	sort(t_stack *a, t_stack *b);
// void	sort_three(t_stack *a);
// void	sort_five(t_stack *a, t_stack *b);
// void	sort_hundred(t_stack *a, t_stack *b);
// void	sort_five_hundred(t_stack *a, t_stack *b);
