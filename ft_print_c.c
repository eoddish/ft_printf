/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:49:25 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:45:30 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(va_list args, int print)
{
	int		len;
	int		n;
	char	x;

	len = 0;
	n = va_arg(args, int);
	x = (char)n;
	if (print)
		write(1, &x, 1);
	len = 1;
	return (len);
}
