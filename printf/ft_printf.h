/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atam <atam@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:28:21 by atam              #+#    #+#             */
/*   Updated: 2024/12/16 12:59:12 by atam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_pointer_len(unsigned long pointer, int *length);
void	ft_putchar_len(char c, int *length);
void	ft_putstr_len(char *str, int *length);
void	ft_putnbr_len(int n, int *length);
void	ft_unputnbr_len(unsigned int n, int *length);
void	ft_puthex(unsigned int n, int *length, char c);
int		ft_printf(const char *string, ...);

#endif
