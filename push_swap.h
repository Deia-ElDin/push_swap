/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:20:55 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	struct s_list	*head;
	struct s_list	*last;
}	t_stack;

// Parsing
void	parsing(char **av, t_stack *stack_a);

// Sort
void	sort(t_list **stack_a, t_list **stack_b);

// Stack Moves
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// Stack Validation Utils
void	stack_map(t_stack *stack, char **av, void (*f)(t_stack*, char*));
bool	stack_iter(t_list *stack, bool (*f)(int, t_list *));
void	stack_create(t_stack *stack_a, char *av);
bool	stack_is_not_duplicated(int value, t_list *next_node);
bool	stack_is_sorted(int value, t_list *next_node);
bool	stack_is_chunk(int value, t_list *next_node);

// Utils
void	avs_iter(char **av, void (*f)(char*));
void	exit_error(t_stack *stack_a, t_stack *stack_b);
void	exit_success(t_stack *stack_a, t_stack *stack_b);
void	print_int_arr(int *arr, int len);

#endif

// void	sort(t_list *a, t_list *b);
// void	sort_three(t_list *a);
// void	sort_five(t_list *a, t_list *b);
// void	sort_hundred(t_list *a, t_list *b);
// void	sort_five_hundred(t_list *a, t_list *b);
