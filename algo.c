/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/27 13:36:00 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:00 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a, 1);
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
}

void	do_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = find_cheapest(*stack_b);
	if (cheapest->above_median == 1
		&& cheapest->target_node->above_median == 1)
		move_top(stack_a, stack_b, cheapest);
	else if (cheapest->above_median == 0
		&& cheapest->target_node->above_median == 0)
		move_bottom(stack_a, stack_b, cheapest);
	final_rotate_a(stack_a, cheapest->target_node);
	final_rotate_b(stack_b, cheapest);
	pa(stack_a, stack_b);
}

int	already_sort(t_list *stack)
{
	int	value;

	if (!stack)
		return (1);
	value = stack->value;
	if (stack->next == NULL)
		return (1);
	stack = stack->next;
	while (stack)
	{
		if (stack->value < value)
			return (0);
		value = stack->value;
		stack = stack->next;
	}
	return (1);
}

void	algo(t_list **stack_a, t_list **stack_b)
{
	init_all(stack_a, stack_b);
	do_move(stack_a, stack_b);
}

void	last_setting_stack_a(t_list **stack_a)
{
	int		median;
	t_list	*smallest;

	init_index(*stack_a);
	median = search_median(*stack_a);
	smallest = is_smallest(*stack_a);
	above_median(*stack_a, median);
	if (smallest->above_median == 1)
		while (*stack_a != smallest)
			ra(stack_a, 1);
	else
		while (*stack_a != smallest)
			rra(stack_a, 1);
}
