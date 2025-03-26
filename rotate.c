/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:27 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:27 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int flag)
{
	t_list	*tmp;
	t_list	*index;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	index = (*stack_a);
	while (index->next != NULL)
		index = index->next;
	index->next = tmp;
	tmp->next = NULL;
	tmp->prev = index;
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	t_list	*index;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	index = (*stack_b);
	while (index->next != NULL)
		index = index->next;
	index->next = tmp;
	tmp->next = NULL;
	tmp->prev = index;
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
