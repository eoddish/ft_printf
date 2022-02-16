/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:39:27 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 15:39:42 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_width(const char **format, va_list args)
{
	int width;

	width = 0;
	if (**format == '*')
	{
		width = va_arg(args, int);
		(*format)++;
	}
	else
		width = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		(*format)++;
	return (width);
}
