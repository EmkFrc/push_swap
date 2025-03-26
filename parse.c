/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <efranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:44:17 by efranco           #+#    #+#             */
/*   Updated: 2025/02/04 12:44:17 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_argument(int argc, char **str, t_list **stack)
{
	int	value;
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(str[i]))
		{
			ft_lstclearall(stack);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		value = ft_atoi(str[i]);
		if (!add_to_list(stack, value))
		{
			ft_lstclearall(stack);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	trigger_error(t_list **stack, char *token)
{
	free(token);
	ft_lstclearall(stack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	parse_one_argument(char *str, t_list **stack)
{
	char	*token;
	int		value;

	token = ft_strtok(str, " ");
	if (str[0] == 0)
		trigger_error(stack, token);
	while (token)
	{
		if (!is_valid_int(token))
			trigger_error(stack, token);
		value = ft_atoi(token);
		if (!add_to_list(stack, value))
			trigger_error(stack, token);
		free(token);
		token = ft_strtok(NULL, " ");
	}
}

void	free_lst(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	current = *stack;
	tmp = NULL;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
