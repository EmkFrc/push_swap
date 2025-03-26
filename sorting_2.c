/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:06:46 by efranco           #+#    #+#             */
/*   Updated: 2025/02/03 15:09:37 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_2(t_list **stack)
{
	int	first;
	int	second;

	first = (*stack)->value;
	second = (*stack)->next->value;
	if (first > second)
		sa(stack, 1);
}
