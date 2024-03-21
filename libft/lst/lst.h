/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:09:34 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/21 08:00:12 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "../libft.h"

typedef struct s_stack
{
	int				content;
	// int				index;
	int				moves;
	int				pivot;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_chunk
{
	int		len;
	t_stack	*cheapest;
}	t_chunk;

t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int content);
// t_stack	*ft_lstmap(t_stack *lst, int *(*f)(int));
// t_stack	*ft_lstnode(t_stack *lst, int index);
// t_stack	*ft_lstpivot(t_stack *stack);

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	ft_lstchunk(t_chunk *chunk, t_stack *stack, int pivot, int size);

int		ft_lstmax(t_stack *stack);
int		ft_lstsize(t_stack *lst);
int		ft_lstmin(t_stack *stack);

#endif