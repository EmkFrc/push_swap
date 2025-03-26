/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:24 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:24 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int flag)
{
	t_list	*index;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	index = (*stack_a);
	while (index->next != NULL)
		index = index->next;
	index->prev->next = NULL;
	index->next = (*stack_a);
	index->prev = NULL;
	(*stack_a)->prev = index;
	(*stack_a) = index;
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **stack_b, int flag)
{
	t_list	*index;

	if ((*stack_b) == NULL || (*stack_b) == NULL)
		return ;
	index = (*stack_b);
	while (index->next != NULL)
		index = index->next;
	index->prev->next = NULL;
	index->next = (*stack_b);
	index->prev = NULL;
	(*stack_b)->prev = index;
	(*stack_b) = index;
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_printf("rrr\n");
}
