/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atam <atam@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:18:26 by atam              #+#    #+#             */
/*   Updated: 2024/12/16 13:49:15 by atam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_checker(const char s, va_list *args, int *len)
{
	if (s == 's')
		ft_putstr_len(va_arg(*args, char *), len);
	else if (s == 'd' || s == 'i')
		ft_putnbr_len(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unputnbr_len(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_puthex(va_arg(*args, unsigned long), len, 'x');
	else if (s == 'X')
		ft_puthex(va_arg(*args, unsigned long), len, 'X');
	else if (s == 'c')
		ft_putchar_len(va_arg(*args, int), len);
	else if (s == 'p')
		ft_pointer_len(va_arg(*args, unsigned long), len);
	else if (s == '%')
		ft_putchar_len('%', len);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	if (!string)
		return (-1);
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_printf_checker(string[i], &args, &length);
			i++;
		}
		else
		{
			ft_putchar_len(string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
