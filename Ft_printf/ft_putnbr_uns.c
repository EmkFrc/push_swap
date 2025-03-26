/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:46:12 by efranco           #+#    #+#             */
/*   Updated: 2024/11/19 13:58:31 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putnbr_uns(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}
