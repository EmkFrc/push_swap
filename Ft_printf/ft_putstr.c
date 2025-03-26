/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:46:44 by efranco           #+#    #+#             */
/*   Updated: 2024/11/18 11:46:44 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
