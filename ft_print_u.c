/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:49:55 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 17:02:05 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned(unsigned int x)
{
	unsigned int	n;
	char			out;

	n = 0;
	if (x >= 0)
		n = x;
	if (n >= 10)
		ft_unsigned(n / 10);
	out = n % 10 + '0';
	write(1, &out, 1);
}

int		ft_print_u(va_list args, int prec, int print)
{
	int				len;
	unsigned int	temp;
	unsigned int	a;
	int				x;

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
		temp = temp / 10;
		len++;
	}
	if (!len)
		len++;
	if (print)
		ft_unsigned(a);
	return (len);
}
