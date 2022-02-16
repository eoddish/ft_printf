/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:44:23 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 16:37:28 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_to_zero(t_struct **a)
{
	t_struct *b;

	b = *a;
	b->len = 0;
	b->left = 0;
	b->zero = 0;
	b->prec = -1;
}

void	ft_parse_min_zer(t_struct **a, const char **format)
{
	t_struct *b;

	b = *a;
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			b->left = 1;
		else
			b->zero = 1;
		(*format)++;
	}
}

void	ft_start_parse(t_struct **a, const char **format, va_list args)
{
	t_struct *b;

	b = *a;
	ft_parse_min_zer(a, format);
	if ((b->width = ft_parse_width(format, args)) < 0)
	{
		b->width = -b->width;
		b->left = 1;
	}
	if (b->left)
		b->zero = 0;
	if (**format == '.')
	{
		b->prec = ft_parse_dot(format, args);
		if (b->prec < 0 || **format == '%')
			b->prec = -1;
		else
			b->zero = 0;
	}
	b->ch = **format;
	if (b->ch != '\0')
		(*format)++;
}

int		ft_readarg(char ch, va_list args, int prec, int p)
{
	int len;

	len = 0;
	if (ch == 'd' || ch == 'i')
		len = ft_print_d_i(args, prec, p);
	else if (ch == 'c')
		len = ft_print_c(args, p);
	else if (ch == 's')
		len = ft_print_s(args, prec, p);
	else if (ch == 'p')
		len = ft_print_p(args, prec, p);
	else if (ch == 'x')
		len = ft_print_x(args, prec, p, 0);
	else if (ch == 'X')
		len = ft_print_x(args, prec, p, 1);
	else if (ch == 'u')
		len = ft_print_u(args, prec, p);
	else if (ch == '%')
	{
		if (p)
			write(1, "%", 1);
		len++;
	}
	return (len);
}

int		ft_parser(const char *format, va_list args)
{
	t_struct	*a;
	int			finlen;

	a = NULL;
	if (!(a = malloc(sizeof(t_struct))))
		return (-1);
	finlen = 0;
	ft_set_to_zero(&a);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_start_parse(&a, &format, args);
			finlen = ft_print_align(&a, args, finlen);
		}
		else
		{
			finlen++;
			write(1, format++, 1);
		}
		ft_set_to_zero(&a);
	}
	free(a);
	return (finlen);
}
