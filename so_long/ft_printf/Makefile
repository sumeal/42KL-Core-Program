# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 08:55:47 by abin-moh          #+#    #+#              #
#    Updated: 2024/11/26 15:43:17 by abin-moh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = ft_printf.c \
	ft_putchar.c \
	ft_putnbr_hex_lower.c \
	ft_putnbr_hex_upper.c \
	ft_putnbr.c \
	ft_putptr.c \
	ft_putstr.c \
	ft_putnbr_unsigned.c \

OFILES = $(FILES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re