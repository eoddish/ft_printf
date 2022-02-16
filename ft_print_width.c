/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:04:27 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 17:03:39 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(int width, int zero)
{
	int n;

	n = 0;
	while (width > 0)
	{
		if (zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width--;
		n++;
	}
	return (n);
}
