/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:46:14 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 19:00:04 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_negative(va_list args)
{
	va_list	temp;
	int		x;

	va_copy(temp, args);
	x = va_arg(temp, int);
	if (x < 0)
		return (1);
	return (0);
}

int	ft_print_d_i(va_list args, int prec, int print)
{
	int		len;
	int		x;

	len = 0;
	x = va_arg(args, int);
	if (!prec && x == 0)
		return (0);
	if (x < 0)
		x = -x;
	if (x < 0)
	{
		if (print)
			write(1, "2147483648", 10);
		return (10);
	}
	if (print)
		ft_putnbr_fd(x, 1);
	if (!x)
		len++;
	while (x)
	{
		x = x / 10;
		len++;
	}
	return (len);
}
