/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:37:41 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 15:38:25 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_dot(const char **format, va_list args)
{
	int prec;

	(*format)++;
	prec = 0;
	if (**format == '*')
	{
		prec = va_arg(args, int);
		(*format)++;
	}
	else
		prec = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		(*format)++;
	return (prec);
}
