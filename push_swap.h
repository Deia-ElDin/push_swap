/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 04:58:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// Parsing
void	parsing(char **av, t_stack **stack_a, t_stack **stack_b);

// Sign Parsing Utils
int		is_multi_signs(char *av, int i);
int		is_sign_after_digit(char *av, int i);
int		is_invalid_after_sign(char *av, int i);

// Stack Moves
void	swap(t_stack **stack);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

// Stack Validation Utils
bool	stack_is_duplicated(int value, t_stack *next_node);
bool	stack_is_sorted(int value, t_stack *next_node);

// Utils
void	avs_iter(char **av, void (*f)(char*));
char	*avs_map(char **av, char *(*f)(const char*, const char*));
void	exit_error(void);
void	exit_success(t_stack *stack_a, t_stack *stack_b);

#endif


// void	sort(t_stack *a, t_stack *b);
// void	sort_three(t_stack *a);
// void	sort_five(t_stack *a, t_stack *b);
// void	sort_hundred(t_stack *a, t_stack *b);
// void	sort_five_hundred(t_stack *a, t_stack *b);
