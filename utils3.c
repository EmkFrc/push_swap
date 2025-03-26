/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:37 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:37 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclearall(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;

	current = *lst;
	while (current)
	{
		if (current)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
		*lst = NULL;
	}
}

int	add_to_list(t_list **stack, int value)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (0);
		tmp = tmp->next;
	}
	new = new_list(value);
	if (*stack == NULL)
	{
		*stack = new;
		return (1);
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	return (1);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_delimiters(char c, const char *delimiters)
{
	int	i;

	i = 0;
	while (delimiters[i])
	{
		if (c == delimiters[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtok(char *str, char const *delimiters)
{
	static char	*s;
	size_t		start;
	size_t		size;
	size_t		i;
	char		*the_string;

	if (str != NULL)
		s = str;
	start = 0;
	while (ft_delimiters(s[start], delimiters))
		start++;
	if (!s[start])
		return (NULL);
	size = ft_strcspn(s + start, delimiters);
	the_string = malloc(sizeof(char) * (size + 1));
	if (!the_string)
		return (NULL);
	i = -1;
	while (++i < size)
		the_string[i] = s[i + start];
	the_string[i] = '\0';
	s = s + start + size;
	return (the_string);
}
