/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/27 14:54:38 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 14:54:38 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_moyenne_value(t_list **stack_a)
{
	t_list	*current;
	int		count;

	count = 0;
	current = *stack_a;
	if (!stack_a)
		return (0);
	while (current)
	{
		count += current->value;
		current = current->next;
	}
	return (count / ft_lstsize(*stack_a));
}

int	under_limit(t_list **stack_a, long limit)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		if (current->value <= limit)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_to_b_quick(t_list **stack_a, t_list **stack_b)
{
	long	limit;

	limit = get_moyenne_value(stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (!under_limit(stack_a, limit))
			limit = get_moyenne_value(stack_a);
		else if ((*stack_a)->value <= limit)
			pb(stack_a, stack_b);
		else
		{
			ra(stack_a, 1);
		}
	}
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	long	len_a;

	len_a = ft_lstsize(*stack_a);
	if (already_sort(*stack_a) == 1)
		return ;
	if (len_a == 2)
	{
		sorting_2(stack_a);
		return ;
	}
	if (len_a == 3)
	{
		sorting_3(stack_a);
		return ;
	}
	push_to_b_quick(stack_a, stack_b);
	sorting_3(stack_a);
	while (*stack_b)
		algo(stack_a, stack_b);
	last_setting_stack_a(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_SUCCESS);
	if (argc == 2)
		parse_one_argument(argv[1], &stack_a);
	else
		parse_argument(argc, argv, &stack_a);
	push_swap(&stack_a, &stack_b);
	free_lst(&stack_a);
	free_lst(&stack_b);
	return (EXIT_SUCCESS);
}
