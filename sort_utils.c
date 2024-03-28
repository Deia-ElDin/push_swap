/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 09:13:05 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/28 13:23:00 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack *a, t_stack *b, t_list *cheapest_node)
{
	int	cheapest;
	int	target;

	cheapest = cheapest_node->moves;
	target = cheapest_node->target->moves;
	if (cheapest > 0 && target > 0 && cheapest-- && target--)
		rr(a, b);
	else if (cheapest < 0 && target < 0 && cheapest++ && target++)
		rrr(a, b);
	else if (cheapest > 0 && cheapest--)
		ra(a);
	else if (cheapest < 0 && cheapest++)
		rra(a);
	cheapest_node->moves = cheapest;
	cheapest_node->target->moves = target;
}

void	pb_and_sort_descending(t_stack *a, t_stack *b)
{
	t_list	*cheapest_node;

	ft_lstset_targets(a->head, b->head);
	cheapest_node = ft_lstget_cheapest(a->head, b->head);
	while (cheapest_node && cheapest_node->moves)
		rotate_to_top(a, b, cheapest_node);
	if (cheapest_node && !cheapest_node->moves)
	{
		while (cheapest_node->target->moves > 0
			&& cheapest_node->target->moves--)
			rb(b);
		while (cheapest_node->target->moves < 0
			&& cheapest_node->target->moves++)
			rrb(b);
		pb(a, b);
	}
}

void	pa_and_sort_ascending(t_stack *a, t_stack *b)
{
	int	max;
	int	b_size;

	max = ft_lstget_node(b->head, ft_lstmax(b->head))->index;
	b_size = ft_lstsize(b->head);
	while (b->head && b->head->content != ft_lstmax(b->head))
	{
		if (max <= (b_size / 2))
			rb(b);
		else
			rrb(b);
	}
	while (b->head)
		pa(b, a);
}

/*
	******************** THE ALGORITHM ********************
	
	* void	pb_and_sort_descending(t_stack *a, t_stack *b)
	{
		First thing first we push the first 2 nodes to b.
		Doesn't matter their values,
		But for sure at this point we don't have any duplication right?
		
		After this we have 2 values in stack b, min and max value.
		
		WE ARE PUSHING TO B AND SORTING IN DESCENDING ORDERS. WHY?
		So once you move it back to A it's will be sorted in ASCENDING ORDER.
		
		Most of the cases you will look for the lower value,
		Assume we pushed the first nodes from a to b (i.e 5 and 8),
		If you have a node with a value of 9 it's target should be 8,
		a node with a value of 6 or 7, their target should be 5.
		but what if you got 3? you dont have less than that in b,
		always look for the highest value, target the 9, 
		so the 3 will be in top of the 9, and once you do rrb,
		3 is now at the bottom.

		Now lets back to code and walk through it step by step.
		while (size--)
			we are decrementing the a stack size by 1 for each iteration,
			we wanna push all stack a to stack b in descending order.
			first we set the targets for each node at stack a
			assume stack a = 9 7 6 3 -1.
			assume stack b = 5 & 8.
			for each iteration we will set:
				1) The targets.
				2) The cheapest node to move.
			
			1st ITERATION:
				1) The targets:
					(look for the lower node, couldn't find, target the highest,
					check ft_lstset_targets.c).
					9 targets 8.
					7 targets 5.
					6 targets 5.
					3 (cant find) then it targets 8.
					-1 (cant find) then it targets 8.
				
				2) The cheapest node:
					(here we will calculate for each node at both stack, how many
						moves it's required to shift the node to the top,
						then we calculate the moves for both the stack a node
						and it's target in stack b, check ft_lstget_cheapest.c)

					The Moves:
						Stack A								Stack B
					9  -> 0 moves                      5 -> 0 moves         
					7  -> 1 move (ra)	               8 -> 1 move (rb or rrb)
					6  -> 2 moves (2 ra)
					3  -> 2 moves (2 rra)
					-1 -> 1 move (1 rra)

					The Cheapest (the node with it's target to go both to top):
					9  //  8 => Cheapest = (0 + 1) = 1 move;
					7  //  5 => Cheapest = (1 + 0) = 1 move;
					6  //  5 => Cheapest = (2 + 0) = 2 moves;
					3  //  8 => Cheapest = (2 + 1) = 3 moves;
					-1 //  8 => Cheapest = (1 + 1) = 2 moves;

										(9 && 8)
					9 is the cheapest node, but we can't move it yet,
					9 is at the top, 8 isn't, so we rotate Stack B
						Stack A								Stack B
					9				                   		  8          
					7	    					      		  5
					6
					3 
					-1
					now we push 9 from a to b.
						Stack A								Stack B
					7	    					      		  9
					6										  8
					3										  5 
					-1
					

			2nd ITERATION: 
					Stack A = (7, 6 , 3, -1),    		Stack B = (9, 8, 5)
					
				1) The targets:
					7 targets 5.
					6 targets 5.
					3 (cant find) then it targets 9.
					-1 (cant find) then it targets 9.
					
				2) The cheapest node:
					The Moves:
						Stack A								Stack B
					7  -> 0 moves                      9 -> 0 moves    
					6  -> 1 moves (1 ra)          	   8 -> 1 move (rb)
					3  -> 2 moves (2 rra)              5 -> 1 move (rrb)
					-1 -> 1 move (1 rra)
					
					The Cheapest (the node with it's target to go both to top):
					7  - 5 => Cheapest = (0 + 1) = 1 move;
					6  - 5 => Cheapest = (1 + 1) = 2 moves;
					3  - 9 => Cheapest = (2 + 0) = 2 moves;
					-1 - 9 => Cheapest = (1 + 0) = 1 m ove;

										(7 && 5)
					7 is the cheapest node, but we can't move it yet,
					7 is at the top, 5 isn't, so we reverse rotate Stack B
						Stack A								Stack B
					7				                   		  5          
					6	    					      		  9
					3										  8
					-1 
					now we push 7 from a to b.
						Stack A								Stack B
					6										  7
					3										  5 
					-1										  9
															  8
				
			3rd ITERATION: 
				Stack A = (6, 3, -1),            Stack B = (7, 5, 9, 8)
				
				1) The targets:
					6 targets 5.
					3  (cannot find) then it targets 9.
					-1 (cannot find) then it targets 9.
					
				2) The cheapest node:
					The Moves:
						Stack A                             Stack B
					6  => 0 moves                     7 => 0 moves    
					3  => 1 move (1 ra)               5 => 1 move (1 ra)
					-1 => 1 moves (1 rra)             9 => 2 moves (2 rrb)
													8 => 1 moves (1 rrb)
					
					The Cheapest (the node with its target to go both to top):
					6  - 5 => Cheapest = (0 + 1) = 1 move;
					3  - 9 => Cheapest = (1 + 2) = 3 moves;
					-1 - 9 => Cheapest = (1 + 2) = 2 moves;

										(6 && 5)
					6 is the cheapest node, but we can't move it yet,
					6 is at the top, 5 isn't, so we rotate Stack B
						Stack A                             Stack B
					6                                         5          
					3                                         9
					-1                                        8
															  7
					now we push 6 from a to b.
						Stack A                             Stack B
					3                                         6
					-1                                        5 
															  9
															  8
															  7
			
			4th ITERATION: 
				Stack A = (3, -1),                  Stack B = (6, 5, 9, 8, 7)
				
			1) The targets:
				3  (cannot find) then it targets 9.
				-1 (cannot find) then it targets 9.
				
			2) The cheapest node:
				The Moves:
					Stack A                             Stack B
				3  => 0 moves                     6 => 0 moves    
				-1 => 1 move (1 rra)              5 => 1 move (1 ra)
												  9 => 2 moves (2 rb)
												  8 => 2 move (2 rrb)
												  7 => 1 move (1 rrb)
				
				The Cheapest (the node with its target to go both to top):
				3  - 9 => Cheapest = (0 + 2) = 2 move;
				-1 - 9 => Cheapest = (1 + 2) = 3 moves;

									(3 && 9)
				3 is the cheapest node, but we can't move it yet,
				3 is at the top, 5 isn't, so we rotate Stack B
					Stack A                             Stack B
				3                                         9          
				-1                                        8
														  7
														  6
														  5
				now we push 3 from a to b.
					Stack A                             Stack B
				-1                                        3
														  9 
														  8
														  7
														  6
														  5
														  4
		
			5th ITERATION: 
				Stack A = (-1),                   Stack B = (3, 9, 8, 7, 6, 5, 4)
				
				1) The targets:
					-1 (cannot find) then it targets 9.
					
				2) The cheapest node:
					The Moves:
						Stack A                             Stack B
				-1 => 0 moves                      3 => 0 moves    
													9 => 1 move (1 ra)
													8 => 2 moves (2 ra)
													7 => 3 moves (3 ra)
													6 => 4 moves (4 ra)
													5 => 5 moves (5 ra)
													4 => 6 moves (6 ra)
				
				The Cheapest (the node with its target to go both to top):
				-1 - 9 => Cheapest = (0 + 1) = 1 move;

								(-1 && 9)
				-1 is the cheapest node and only node,
				but we can't move it yet,
				-1 is at the top, 9 isn't, so we rotate Stack B
					Stack A                             	Stack B
						-1								  	   9 
																8
																7
																6
																5
																4
																3
				now we push -1 from a to b.
					Stack A                             	Stack B
					(empty)								  	   -1 
																9
																8
																7
																6
																5
																4
																3

	* void	pa_and_sort_ascending(t_stack *a, t_stack *b)
	{
		basically we checking out received list from stack b, 
		it's not fully sorted,
		it's mostly divided into 2 portions each one of them is sorted,
		but one of the portion must go on top or below the other,
		that's why we need to decided where is the small portion,
		we used the max value for that.

		max = ft_lstget_node(b->head, ft_lstmax(b->head))->index;	
			We get the max value.
			Then we get the node itself, then we get it's location.
		
		b_size = ft_lstsize(b->head);
		
		while (b->head && b->head->content != ft_lstmax(b->head))
		{
			while current content is not the max value,
			and if (the max content index is less than or equal to 
				the half of the b size)
				then rotate the b stack.
			else
				reverse rotate the b stack.
		}

		while (b->head)
			push all back to a.
	}
*/
