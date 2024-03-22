/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:09:34 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/22 22:06:52 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "../libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	int				moves;
	int				pivot;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_chunk
{
	int		len;
	t_list	*cheapest;
}	t_chunk;

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstset_chunk(t_list *stack, int pivot, int size);

// t_list	*ft_lstmap(t_list *lst, int *(*f)(int));
// t_list	*ft_lstnode(t_list *lst, int index);
// t_list	*ft_lstpivot(t_list *stack);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lstpush_chunk(t_list **from, t_list **to, t_list *node,
			int pivot);

int		ft_lstmax(t_list *stack);
int		ft_lstsize(t_list *lst);
int		ft_lstmin(t_list *stack);

#endif