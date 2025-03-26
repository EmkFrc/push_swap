/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/27 13:36:13 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:13 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
		rr(stack_a, stack_b);
	init_index(*stack_a);
	init_index(*stack_b);
}

void	move_bottom(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
		rrr(stack_a, stack_b);
	init_index(*stack_a);
	init_index(*stack_b);
}
