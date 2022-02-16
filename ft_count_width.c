/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:00:20 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 15:35:40 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_count_width(t_struct *a)
{
	if (a->prec == -1 || a->ch == 'c')
		a->width = a->width - a->len;
	else if (a->ch != 's' && a->ch != '%')
		a->width = a->width - ft_max(a->len, a->prec);
	else
		a->width = a->width - ft_min(a->len, a->prec);
	return (a->width);
}
