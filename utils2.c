/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/27 13:36:34 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:34 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *theString)
{
	long	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((theString[i] >= 9 && theString[i] <= 13) || (theString[i] == 32))
		i++;
	if (theString[i] == '-' || theString[i] == '+')
	{
		if (theString[i] == '-')
			sign *= -1;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9' && theString[i])
	{
		res = res * 10 + (theString[i] - 48);
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *theString)
{
	int	i;

	i = 0;
	while (theString[i])
		i++;
	return (i);
}

int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

t_list	*new_list(int value)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->value = value;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
