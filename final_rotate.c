/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/27 13:36:05 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:05 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate_a(t_list **stack, t_list *cheapest)
{
	while (*stack != cheapest)
	{
		if (cheapest->above_median == 1)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

void	final_rotate_b(t_list **stack, t_list *cheapest)
{
	while (*stack != cheapest)
	{
		if (cheapest->above_median == 1)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}
