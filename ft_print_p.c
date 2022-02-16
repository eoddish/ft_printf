/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:05:02 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:50:52 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(va_list args, int prec, int print)
{
	int				len;
	unsigned long	n;
	unsigned long	temp;
	void			*x;

	x = va_arg(args, void *);
	len = 0;
	n = 0;
	if (x != NULL)
	{
		n = (long)x;
		temp = n;
		while (temp)
		{
			temp = temp / 16;
			len++;
		}
	}
	if (!len && prec)
		len++;
	if (print && len)
		ft_hexadec(n, 0);
	return (len);
}
