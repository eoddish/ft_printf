# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoddish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:40:26 by eoddish           #+#    #+#              #
#    Updated: 2021/01/25 17:40:19 by eoddish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_parser.c ft_printf.c ft_print_d_i.c\
			  ft_print_s.c ft_print_x.c ft_print_u.c\
			  ft_print_p.c ft_print_c.c ft_parse_dot.c\
			  ft_parse_width.c ft_print_align.c\
			  ft_print_width.c ft_print_prec.c \
			  ft_count_width.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c	
			$(CC) $(CFLAGS) -c $< -o $@

RM			= rm -f

AR			= ar -rcs

LIBFT		= libft

LIBFT_NAME	= libft.a

MAKE		= make -C

$(NAME):	$(OBJS)
			$(MAKE) $(LIBFT)
			cp $(LIBFT)/$(LIBFT_NAME) $(NAME)
			$(AR) $@ $^

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(LIBFT)/$(LIBFT_NAME) $(LIBFT)/*.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re

.SILENT:
