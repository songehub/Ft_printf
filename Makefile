# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 16:17:27 by ccrecent          #+#    #+#              #
#    Updated: 2023/01/05 16:17:28 by ccrecent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_printf.c	\
		ft_putchar.c	\
		ft_putstr.c	\
		ft_putendl.c	\
		ft_putnbr.c	\
		
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGC = -Wall -Wextra -Werror
NAME = lib_printf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -crs $@ $^

bonus: $(OBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re