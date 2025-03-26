/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/27 13:36:10 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:10 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*is_smallest(t_list *stack_a)
{
	t_list	*smallest;

	smallest = NULL;
	while (stack_a)
	{
		if (!smallest || stack_a->value < smallest->value)
			smallest = stack_a;
		stack_a = stack_a->next;
	}
	return (smallest);
}

void	search_close_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*close_target;
	t_list	*current_a;

	if (!stack_a)
		return ;
	while (stack_b)
	{
		close_target = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if ((!close_target || close_target->value > current_a->value)
				&& stack_b->value < current_a->value)
				close_target = current_a;
			current_a = current_a->next;
		}
		if (close_target == NULL)
			stack_b->target_node = is_smallest(stack_a);
		else
			stack_b->target_node = close_target;
		stack_b = stack_b->next;
	}
}

int	search_median(t_list *stack)
{
	int	median;
	int	size;

	median = 0;
	size = ft_lstsize(stack);
	median = size / 2;
	if (size % 2 == 1)
		median++;
	return (median);
}

void	above_median(t_list *stack, int median)
{
	while (stack)
	{
		if (stack->index < median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}

t_list	*find_cheapest(t_list *stack)
{
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
