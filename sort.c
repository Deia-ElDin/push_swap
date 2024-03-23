/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 05:55:31 by dehamad           #+#    #+#             */
/*   Updated: 2024/03/24 02:18:22 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack_a)
{
	if (stack_a->head->content > stack_a->head->next->content)
		sa(stack_a);
}

static void	sort_three(t_stack *stack_a)
{
	t_list	*head;
	int		num1;
	int		num2;
	int		max;

	head = stack_a->head;
	num1 = stack_a->head->content;
	num2 = stack_a->head->next->content;
	max = ft_lstmax(stack_a->head);
	if (num1 == max)
		ra(stack_a);
	else if (num2 == max)
		rra(stack_a);
	if (stack_a->head->content > stack_a->head->next->content)
		sa(stack_a);
}

int	*ft_lstmax_three(t_list *list)
{
	int		*max_three;

	max_three = (int *)malloc(3 * sizeof(int));
	if (max_three == NULL)
		return (NULL);
	max_three[0] = INT_MIN;
	max_three[1] = INT_MIN;
	max_three[2] = INT_MIN;
	while (list)
	{
		if (list->content > max_three[0])
		{
			max_three[2] = max_three[1];
			max_three[1] = max_three[0];
			max_three[0] = list->content;
		}
		else if (list->content > max_three[1])
		{
			max_three[2] = max_three[1];
			max_three[1] = list->content;
		}
		else if (list->content > max_three[2])
			max_three[2] = list->content;
		list = list->next;
	}
	return (max_three);
}

// void print_max_three(int *max_three) 
// {
//     printf("Max three values: %d, %d, %d\n", max_three[0], max_three[1], max_three[2]);
// }

static void	push_2nodes_to_b(t_stack *stack_a, t_stack *stack_b, int *max_three)
{
	int		pushes;

	pushes = 0;
	while (pushes < 2)
	{
		if (ft_ismaxthree(stack_a->head->content, max_three))
			ra(stack_a);
		else if (++pushes)
			pb(stack_a, stack_b);
	}
}

static void	sort_above_three(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	*max_three;

	size = stack_a->size;
	max_three = ft_lstmax_three(stack_a->head);
	if (!max_three)
		exit_error(stack_a, stack_b);
	push_2nodes_to_b(stack_a, stack_b, max_three);
	// ft_printf(1, "stack_a: \n%l\n", stack_a->head);
	// ft_printf(1, "stack_b: \n%l\n", stack_b->head);
	size -= 2;
	while (size-- > 3)
		push_and_sort(stack_a, stack_b, max_three);
	sort_three(stack_a);
	while (stack_b->head && stack_b->head->content != ft_lstmax(stack_b->head))
		rrb(stack_b);
	while (stack_b->head)
		pa(stack_b, stack_a);
	// ft_printf(1, "stack_a: \n%l\n", stack_a->head);
	// ft_printf(1, "stack_b: \n%l\n", stack_b->head);
	free(max_three);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*head_a;
	int		size;

	if (stack_iter(stack_a, stack_is_sorted))
		exit_success(stack_a, stack_b);
	size = stack_a->size;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_above_three(stack_a, stack_b);
	if (stack_iter(stack_a, stack_is_sorted))
		exit_success(stack_a, stack_b);
}

// ./push_swap 35 50 11 49 36 100 78 34 88 56 15 24 84 40 13 69 66 74 53 79 5 23 61 75 96 17 39 48 97 70 55 62 3 57 86 99 98 92 65 47 94 8 14 76 42 6 2 89 27 38 4 95 91 58 44 80 18 12 52 16 32 67 68 83 30 19 71 63 59 72 77 46 9 81 7 28 90 60 25 64 85 54 51 73 21 22 43 1 82 93 87 29 37 33 20 31 41 45 26 10

// ./push_swap 35 50 11 49 36 100 78 34 88 56 15 24 84 40 13 69 66 74 53 79 5 23 61 75 96 17 39 48 97 70 55 62 3 57 86 99 98 92 65 47 94 

// if (cheapest_node->moves > 0 && cheapest_node->moves--)
		// 	ra(stack_a);
		// else if (cheapest_node->moves < 0 && cheapest_node->moves++)
		// 	rra(stack_b);


// static void	sort_five(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_list	*last_node;
// 	int		min;

// 	while (*stack_a && ft_lstsize(*stack_a) > 3)
// 	{
// 		last_node = ft_lstlast(*stack_a);
// 		min = ft_lstmin(*stack_a);
// 		if ((*stack_a)->content == min)
// 			pb(stack_a, stack_b);
// 		else if (last_node->prev->content == min)
// 			(rra(stack_a), rra(stack_a));
// 		else if (last_node->content == min)
// 			rra(stack_a);
// 		else
// 			ra(stack_a);
// 	}
// 	sort_three(stack_a);
// 	pa(stack_b, stack_a);
// 	pa(stack_b, stack_a);
// }