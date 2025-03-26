/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:53 by efranco           #+#    #+#             */
/*   Updated: 2024/11/19 14:04:49 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb)
{
	const char	base[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (nb > 15)
		count += ft_putnbr_hex(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
