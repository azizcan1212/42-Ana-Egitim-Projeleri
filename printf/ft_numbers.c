/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atam <atam@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:24:11 by atam              #+#    #+#             */
/*   Updated: 2024/12/16 13:48:26 by atam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_recursive(unsigned long num, int *len, const char *base)
{
	if (num >= 16)
	{
		ft_puthex_recursive(num / 16, len, base);
	}
	ft_putchar_len(base[num % 16], len);
}

void	ft_pointer_len(unsigned long pointer, int *length)
{
	const char	*base_character = "0123456789abcdef";

	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		*length += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*length) += 2;
		ft_puthex_recursive(pointer, length, base_character);
	}
}

void	ft_puthex(unsigned int number, int *len, char format)
{
	const char	*base_hex;

	if (format == 'X')
		base_hex = "0123456789ABCDEF";
	if (format == 'x')
		base_hex = "0123456789abcdef";
	if (number >= 16)
	{
		ft_puthex(number / 16, len, format);
	}
	ft_putchar_len(base_hex[number % 16], len);
}

void	ft_putnbr_len(int number, int *len)
{
	char	c;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number *= (-1);
		(*len)++;
	}
	if (number >= 10)
	{
		ft_putnbr_len(number / 10, len);
	}
	c = (number % 10) + '0';
	write(1, &c, 1);
	(*len)++;
}

void	ft_unputnbr_len(unsigned int number, int *len)
{
	char	c;

	if (number >= 10)
	{
		ft_unputnbr_len(number / 10, len);
	}
	c = (number % 10) + '0';
	write(1, &c, 1);
	(*len)++;
}
