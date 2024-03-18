/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:09:34 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/19 02:05:18 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

# include "../libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				size;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	ft_lstcreate(t_stack **lst, char **split, void (*f)());
t_stack	*ft_lstnew(int content, int index);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
bool	ft_lstiter(t_stack *lst, bool (*f)(int, t_stack *));
t_stack	*ft_lstmap(t_stack *lst, int *(*f)(int));

#endif