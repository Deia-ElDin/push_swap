/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:09:34 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/25 08:15:37 by dehamad          ###   ########.fr       */
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
	int				cheapest;
	struct s_list	*target;
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
t_list	*ft_lstcheapest(t_list *list_a, t_list *list_b);
t_list	*ft_lstget_node(t_list *list, int content);

void	ft_lstadd_back(t_list **lst, t_list *new, t_list *last);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_lsttarget(t_list *list_a, t_list *list_b, int *max_three);

int		ft_lstmax(t_list *stack);
int		ft_lstsize(t_list *lst);
int		ft_lstmin(t_list *stack);
int		*ft_lstmax_three(t_list *list);

#endif