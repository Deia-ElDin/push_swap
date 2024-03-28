/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_cheapest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:15:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/28 13:58:12 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

static	void	ft_list_moves(t_list *list)
{
	int	size;
	int	index;

	size = ft_lstsize(list);
	index = 0;
	if (size == 1)
	{
		list->moves = 0;
		list->index = 0;
		return ;
	}
	while (list)
	{
		if (index <= (size / 2))
			list->moves = index;
		else
			list->moves = (size - index) * -1;
		list->index = index++;
		list = list->next;
	}
}

static int	ft_cheapest_moves(int moves1, int moves2)
{
	if ((moves1 < 0 && moves2 < 0) || (moves1 > 0 && moves2 > 0))
	{
		if (ft_abs(moves1) > ft_abs(moves2))
			return (ft_abs(moves1));
		return (ft_abs(moves2));
	}
	else if (!moves1 && moves2)
		return (ft_abs(moves2));
	else if (moves1 && !moves2)
		return (ft_abs(moves1));
	return (ft_abs(moves1) + ft_abs(moves2));
}

static void	ft_check_different_sign_moves(t_list *cheapest_node)
{
	int	fewer_moves;
	int	more_moves;
	int	total_moves;
	int	index;

	if (abs(cheapest_node->moves) == abs(cheapest_node->target->moves))
		return ;
	if (ft_abs(cheapest_node->moves) < ft_abs(cheapest_node->target->moves))
	{
		fewer_moves = cheapest_node->moves;
		more_moves = cheapest_node->target->moves;
		total_moves = ft_abs(fewer_moves) + ft_abs(more_moves);
		index = cheapest_node->target->index;
		if ((index - ft_abs(fewer_moves)) <= total_moves)
			cheapest_node->target->moves = index;
	}
	else
	{
		fewer_moves = cheapest_node->target->moves;
		more_moves = cheapest_node->moves;
		total_moves = ft_abs(fewer_moves) + ft_abs(more_moves);
		index = cheapest_node->index;
		if ((index - ft_abs(fewer_moves)) <= total_moves)
			cheapest_node->moves = index;
	}
}

t_list	*ft_lstget_cheapest(t_list *list_a, t_list *list_b)
{
	t_list	*cheapest_node;
	int		moves;

	if (!list_a || !list_b)
		return (NULL);
	ft_list_moves(list_a);
	ft_list_moves(list_b);
	moves = INT_MAX;
	cheapest_node = NULL;
	while (list_a)
	{
		list_a->cheapest = ft_cheapest_moves(list_a->moves,
				list_a->target->moves);
		if (list_a->cheapest < moves)
		{
			cheapest_node = list_a;
			moves = list_a->cheapest;
		}
		if (ft_isdifferent_sign(cheapest_node->moves,
				cheapest_node->target->moves))
			ft_check_different_sign_moves(cheapest_node);
		list_a = list_a->next;
	}
	return (cheapest_node);
}
/*
	* t_list	*ft_lstget_cheapest(t_list *list_a, t_list *list_b)
	{
		the purpose of this function is to find the cheapest node in list_a.
		we loop over the list_a, and we calculate the moves for each node,
		we call our inner function ft_list_moves, to set the moves for each node.
		
		list_a->cheapest = ft_cheapest_moves(list_a->moves,
				list_a->target->moves);
		the purpose of this function is to calculate the moves for each node,
		based on the function before it ft_list_moves.
		we calculate the moves for each node, and we compare it with the 
		previous cheapest node.
		if the current node moves is less than the previous cheapest node moves,
		we set the current node as the cheapest node.
		
		if (ft_isdifferent_sign(cheapest_node->moves,
				cheapest_node->target->moves))
			ft_check_different_sign_moves(cheapest_node);

		this function is so important, 
		lets assume we have a node with +4 moves (4 ra) && -6 moves (6 rra) for 
		it's target, that's a total of 10 moves, yet ... 
		at some cases it's better instead of moving in 2 different directions,
		we move both at the same direction 
		so we do 4 rr and for the target we continuo with rb till we get it to 
		the top,
		basically we are trying to minimize the total moves.
	}

	* static	void	ft_list_moves(t_list *list)
	{
		the purpose of this function is to set the moves for each node.
		we loop over the list, and we set the moves for each node.
		if the index is less than the half of the size, 
		we set the moves to the index cuz that's how far we are from top.
		otherwise, we set the moves to the size of that (stack - index) * -1,
		the negative sign is to indicate that we will use rra instead of ra.
		the positive sign is to indicate that we will use ra.
	}
	
	* static int	ft_cheapest_moves(int moves1, int moves2)
	{
		take 2 moves, the moves of the current node and the moves of it's target.
		
		if both moves are in the same direction,
			we return the maximum of the 2 moves.
			assume node takes 4 and target takes 6, we return 6.
			4 goes rr and 2 rb.
			
		if the current node moves is 0 and the target moves is not 0,
		assume the current node is at the top, and the target is somewhere else, 
		but not the top, so the total moves are the target moves. Vice versa.

		otherwise, we return the sum of the 2 moves.
	}

	* static void	ft_check_different_sign_moves(t_list *cheapest_node)
	{
		
		the purpose of this function is to handle cases where nodes in the stack 
		have different signs for their moves, indicating they require opposite 
		rotations to reach their target positions. Its primary goal is to 
		optimize the movement strategy by identifying scenarios where combining 
		rotations can lead to more efficient solutions.

		It identifies nodes with different signs for their move counts.

		Determines nodes with fewer and more moves.

		Calculates the total moves required.

		Adjusts moves to optimize rotation combinations.

		Efficiently combines rotations to minimize total moves needed.

		The main idea there is to switch the sign of the more moves node.

		Overall, the ft_check_different_sign_moves function plays a crucial role 
		in optimizing the movement strategy of the sorting algorithm by 
		efficiently handling cases where nodes require opposite rotations to 
		reach their target positions. It ensures that the algorithm can 
		capitalize on combined rotations to minimize the total number of moves, 
		thereby enhancing its efficiency and performance.
	}
*/
