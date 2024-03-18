/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:29:27 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/18 05:22:44 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

// Parsing
bool	parsing(int ac, char **av);

// Parsing Utils
int		is_multi_signs(char *av, int i);
int		is_sign_afterwords(char *av, int i);

// Utils
void	avs_iter(char **av, void (*f)(char*));
char	*avs_map(int ac, char **av, char **avs_str);
void	exit_error(void);

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