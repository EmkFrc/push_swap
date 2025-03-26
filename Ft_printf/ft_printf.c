/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <rubisingame@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:42:23 by efranco           #+#    #+#             */
/*   Updated: 2024/12/02 11:37:31 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percentage(const char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_put_hex(va_arg(args, unsigned long), 1);
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnbr_uns(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int));
	else if (specifier == 'X')
		count += ft_putnbr_hex_maj(va_arg(args, unsigned int));
	else if (specifier == '%')
		count += ft_put_per();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (format == 0)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += percentage(format[i + 1], args);
			i++;
		}
		else
		count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
