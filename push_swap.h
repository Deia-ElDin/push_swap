/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 01:43:58 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stacks;

// Parsing
void	parsing(char **av, t_list **stack_a, t_list **stack_b);

// Sign Parsing Utils
int		is_multi_signs(char *av, int i);
int		is_sign_after_digit(char *av, int i);
int		is_invalid_after_sign(char *av, int i);

// Stack Validation Utils
bool	stack_is_duplicated(int value, t_list *next_node);
bool	stack_is_sorted(int value, t_list *next_node);

// Utils
void	avs_iter(char **av, void (*f)(char*));

// char	*avs_map(int ac, char **av, char **avs_str);
char	*avs_map(char **av, char *(*f)(const char*, const char*));
void	exit_error(void);
void	exit_success(t_list *stack_a, t_list *stack_b);

#endif

// void	swap(t_stack *stack);
// void	push(t_stack *from, t_stack *to);
// void	rotate(t_stack *stack);
// void	reverse_rotate(t_stack *stack);
// void	swap_both(t_stack *a, t_stack *b);
// void	push_both(t_stack *a, t_stack *b);
// void	rotate_both(t_stack *a, t_stack *b);
// void	reverse_rotate_both(t_stack *a, t_stack *b);
// void	sort(t_stack *a, t_stack *b);
// void	sort_three(t_stack *a);
// void	sort_five(t_stack *a, t_stack *b);
// void	sort_hundred(t_stack *a, t_stack *b);
// void	sort_five_hundred(t_stack *a, t_stack *b);
