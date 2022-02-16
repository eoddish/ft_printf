/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoddish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:24:07 by eoddish           #+#    #+#             */
/*   Updated: 2021/01/25 17:13:22 by eoddish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_struct
{
	int			left;
	int			len;
	int			width;
	char		ch;
	int			zero;
	int			prec;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_readarg(char ch, va_list args, int prec, int p);
int				ft_parser(const char *format, va_list args);
int				ft_count_width(t_struct *a);
int				ft_print_right(t_struct **a, va_list args, int finlen);
int				ft_print_width(int width, int zero);
int				ft_print_prec(t_struct **a, int finlen);
int				ft_print_left(t_struct **a, va_list args, int finlen);
int				ft_print_d_i(va_list args, int prec, int print);
int				ft_print_u(va_list args, int prec, int print);
void			ft_hexadec(unsigned long x, int capital);
int				ft_print_p(va_list args, int prec, int print);
int				ft_print_x(va_list args, int prec, int print, int capital);
int				ft_print_s(va_list args, int prec, int print);
int				ft_print_c(va_list args, int print);
int				ft_parse_dot(const char **format, va_list args);
int				ft_parse_width(const char **format, va_list args);
int				is_negative(va_list args);
int				ft_print_align(t_struct **a, va_list args, int finlen);
#endif
