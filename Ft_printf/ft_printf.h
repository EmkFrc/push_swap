/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:05:45 by efranco           #+#    #+#             */
/*   Updated: 2024/12/02 11:37:47 by efranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_put_hex(unsigned long num_hex, int flag);
int	ft_put_per(void);
int	ft_putchar(char c);
int	ft_putnbr_hex_maj(unsigned int nb);
int	ft_putnbr_hex(unsigned int nb);
int	ft_putnbr_uns(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);
int	percentage(const char specifier, va_list args);

#endif
