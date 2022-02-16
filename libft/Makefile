# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoddish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:40:26 by eoddish           #+#    #+#              #
#    Updated: 2021/01/25 18:47:00 by eoddish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_putnbr_fd.c ft_putchar_fd.c ft_atoi.c\
			  ft_isdigit.c ft_strlen.c


OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

CC			= gcc

RM			= rm -f

AR			= ar

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(AR) -rcs $@ $^

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUSOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, all

.SILENT:
