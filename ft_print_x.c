/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:23:15 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:44:00 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexadec(unsigned long x, int capital)
{
	unsigned long	n;
	char			out;

	n = 0;
	if (x >= 0)
		n = x;
	if (n >= 16)
		ft_hexadec(n / 16, capital);
	if (n % 16 <= 9)
		out = n % 16 + '0';
	else if (capital)
		out = n % 16 + 7 + '0';
	else
		out = n % 16 + 39 + '0';
	write(1, &out, 1);
}

int		ft_print_x(va_list args, int prec, int print, int capital)
{
	int				len;
	unsigned long	temp;
	unsigned long	a;
	long			x;

	len = 0;
	x = va_arg(args, int);
	if (!prec && x == 0)
		return (0);
	if (x < 0)
		a = 4294967295 + x + 1;
	else
		a = x;
	temp = a;
	while (temp)
	{
		temp = temp / 16;
		len++;
	}
	if (!len)
		len++;
	if (print)
		ft_hexadec(a, capital);
	return (len);
}
