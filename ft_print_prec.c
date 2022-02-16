/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:06:14 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:54:13 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_prec(t_struct **a, int finlen)
{
	t_struct	*b;
	int			t;

	b = *a;
	t = b->prec;
	b->prec = b->prec - b->len;
	if (b->ch != 'c' && b->ch != 's')
		while (b->prec > 0)
		{
			if ((!b->left && b->ch != 's') || b->left)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			finlen++;
			b->prec--;
		}
	b->prec = t;
	return (finlen);
}
