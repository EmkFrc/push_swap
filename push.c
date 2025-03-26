/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:22 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:22 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if ((*stack_b) == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	if ((*stack_b) != NULL)
		(*stack_b)->prev = NULL;
	tmp->next = (*stack_a);
	if ((*stack_a) != NULL)
		(*stack_a)->prev = tmp;
	tmp->prev = NULL;
	*stack_a = tmp;
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if ((*stack_a) == NULL)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	if ((*stack_a) != NULL)
		(*stack_a)->prev = NULL;
	tmp->next = (*stack_b);
	if ((*stack_b != NULL))
		(*stack_b)->prev = tmp;
	tmp->prev = NULL;
	*stack_b = tmp;
	ft_printf("pb\n");
}
