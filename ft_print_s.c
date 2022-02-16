/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:38:04 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:56:32 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(va_list args, int prec, int print)
{
	int		len;
	char	*x;

	len = 0;
	x = va_arg(args, char *);
	if (!prec)
		return (0);
	if (x == NULL)
		x = "(null)";
	if (prec == -1)
		prec = ft_strlen(x);
	while (prec && *x)
	{
		if (print)
			write(1, x, 1);
		x++;
		len++;
		prec--;
	}
	return (len);
}
