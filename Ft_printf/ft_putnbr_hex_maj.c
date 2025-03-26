/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:20 by efranco           #+#    #+#             */
/*   Updated: 2024/11/19 14:01:47 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_maj(unsigned int nb)
{
	const char	base[] = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (nb > 15)
		count += ft_putnbr_hex_maj(nb / 16);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
