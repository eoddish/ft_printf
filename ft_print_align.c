/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_align.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:53:06 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:32:39 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_p(t_struct **a, int finlen)
{
	t_struct *b;

	b = *a;
	if (b->ch == 'p')
	{
		finlen += 2;
		b->len -= 2;
	}
	return (finlen);
}

int	ft_print_minus(t_struct *b, va_list args, int finlen)
{
	if (b->ch == 'd' || b->ch == 'i')
		if (is_negative(args))
		{
			write(1, "-", 1);
			finlen++;
		}
	return (finlen);
}

int	ft_print_left(t_struct **a, va_list args, int finlen)
{
	t_struct	*b;
	va_list		temp;

	b = *a;
	finlen = ft_print_minus(b, args, finlen);
	if (b->ch == 'p')
	{
		write(1, "0x", 2);
		b->len += 2;
	}
	va_copy(temp, args);
	b->len += ft_readarg(b->ch, temp, b->prec, 0);
	b->width = ft_count_width(b);
	if (b->ch == 'd' || b->ch == 'i')
		if (is_negative(args))
			b->width--;
	finlen = ft_process_p(a, finlen);
	finlen = ft_print_prec(a, finlen);
	ft_readarg(b->ch, args, b->prec, 1);
	finlen += ft_print_width(b->width, b->zero);
	finlen += b->len;
	return (finlen);
}

int	ft_print_right(t_struct **a, va_list args, int finlen)
{
	t_struct	*b;
	va_list		temp;

	b = *a;
	if (b->ch == 'p')
		b->len += 2;
	va_copy(temp, args);
	b->len += ft_readarg(b->ch, temp, b->prec, 0);
	if (b->ch == 'd' || b->ch == 'i')
		if (is_negative(args))
			b->width--;
	b->width = ft_count_width(b);
	if (!b->zero)
		finlen += ft_print_width(b->width, b->zero);
	finlen = ft_print_minus(b, args, finlen);
	if (b->ch == 'p')
		write(1, "0x", 2);
	if (b->zero)
		finlen += ft_print_width(b->width, b->zero);
	finlen = ft_process_p(a, finlen);
	finlen = ft_print_prec(a, finlen);
	ft_readarg(b->ch, args, b->prec, 1);
	finlen += b->len;
	return (finlen);
}

int	ft_print_align(t_struct **a, va_list args, int finlen)
{
	t_struct *b;

	b = *a;
	if (b->left)
		finlen = ft_print_left(a, args, finlen);
	else
		finlen = ft_print_right(a, args, finlen);
	return (finlen);
}
