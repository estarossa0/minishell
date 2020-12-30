# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikhadem <ikhadem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 08:01:27 by ikhadem           #+#    #+#              #
#    Updated: 2020/12/30 09:06:55 by ikhadem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := TermCaped

CC := gcc

SRC :=	main.c \
		sources/IO/ft_putchar_fd.c \
		sources/IO/ft_putstr_fd.c \
		sources/terminal/terminal.c \
		sources/terminal/ft_capabilities.c \
		sources/string/str_manip.c \
		sources/terminal/insert_mode.c \
		sources/terminal/delete_mode.c

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
			@echo "$(NAME) : Removed Objects"

fclean:		clean
			@rm -f $(NAME)
			@echo "$(NAME) : Removed Binary"

re:			fclean
			@rm -f $(NAME)
			@echo "$(NAME) : Recompiled Project"