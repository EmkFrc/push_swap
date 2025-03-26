/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:44:02 by efranco           #+#    #+#             */
/*   Updated: 2024/11/19 14:00:19 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long num_hex, int flag)
{	
	const char	base[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (!num_hex)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	if (flag == 1)
	{
		ft_putstr("0x");
		count += 2;
	}
	if (num_hex > 15)
		count += ft_put_hex(num_hex / 16, 0);
	count += write(1, &base[num_hex % 16], 1);
	return (count);
}
