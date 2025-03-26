/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:36:32 by efranco           #+#    #+#             */
/*   Updated: 2025/01/27 13:36:32 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_word_size(const char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

int	ft_count_s(const char *s, char c)
{
	int	flag;
	int	i;
	int	count;

	flag = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			count++;
			flag = 1;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *src, int j, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = src[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		index;
	int		word_len;
	char	**array;

	i = 0;
	index = 0;
	array = malloc(sizeof(char *) * (ft_count_s(s, c) + 1));
	if (!array)
		return (NULL);
	while (s[i] != '\0' && index < ft_count_s(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word_len = ft_word_size(s, c, i);
			array[index] = ft_strndup(s, i, word_len);
			i += word_len;
			index++;
		}
	}
	array[index] = NULL;
	return (array);
}

int	ft_atoi(const char *theString)
{
	int	i;
	int	res;
	int	sign;

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
