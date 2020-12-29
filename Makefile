# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 08:01:27 by ikhadem           #+#    #+#              #
#    Updated: 2020/12/29 08:40:48 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := TermCaped

CC := gcc

SRC :=	main.c \
		sources/IO/ft_putchar_fd.c \
		sources/IO/ft_putstr_fd.c \
		sources/terminal/terminal.c \
		sources/terminal/ft_capabilities.c

OBJ := $(SRC:.c=.o)

HEADERS := -I Headers

LIBS := -lncurses -ltermcap

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(HEADERS) $(LIBS) $(OBJ) -o $(NAME)
			@echo "done"

%.o : %.c
			@$(CC) -c $(HEADERS) $< -o $@

clean:
			@rm -f $(OBJ)
			@echo "Removed Objects"

fclean:		clean
			@rm -f $(NAME)
			@echo "Removed Binary"

re:			fclean
			@rm -f $(NAME)
			@echo "Recompiled Project"