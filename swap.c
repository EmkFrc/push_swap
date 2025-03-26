/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:30 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:30 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int flag)
{
	t_list	*tmp;

	if ((*stack_a) == NULL)
		return ;
	if ((*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	(*stack_a)->next = tmp;
	(*stack_a)->prev = NULL;
	tmp->prev = (*stack_a);
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_list **stack_b, int flag)
{
	t_list	*tmp;

	if ((*stack_b) == NULL)
		return ;
	if ((*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	(*stack_b)->next = tmp;
	(*stack_b)->prev = NULL;
	tmp->prev = (*stack_b);
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
