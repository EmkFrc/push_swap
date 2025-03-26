/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/27 13:36:08 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:08 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_list *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	init_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->above_median == 0)
			stack_b->cost = len_b - (stack_b->index);
		else
			stack_b->cost = stack_b->index;
		if (stack_b->target_node->above_median == 1)
			stack_b->cost += stack_b->target_node->index;
		else
			stack_b->cost += len_a - stack_b->target_node->index;
		stack_b = stack_b->next;
	}
}

void	init_cheapest(t_list *stack)
{
	long	best_cost;
	t_list	*cheapest;

	if (!stack)
		return ;
	best_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost < best_cost)
		{
			best_cost = stack->cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}

void	init_all(t_list **stack_a, t_list **stack_b)
{
	int	median_a;
	int	median_b;

	median_a = search_median(*stack_a);
	median_b = search_median(*stack_b);
	init_index(*stack_a);
	init_index(*stack_b);
	search_close_target(*stack_a, *stack_b);
	above_median(*stack_a, median_a);
	above_median(*stack_b, median_b);
	init_cost(*stack_a, *stack_b);
	init_cheapest(*stack_b);
}
