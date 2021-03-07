# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arraji <arraji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 13:57:03 by arraji            #+#    #+#              #
#    Updated: 2021/03/07 18:11:36 by arraji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar rcs
FLAGS = -g -Wall -Wextra -Werror
OBJECT_FOLDER = ./objects
SRC_FOLDER = ./src
HEADERS = ./includes
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

SRC_FILES  =	ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_itoa.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_lst_test.c \
				ft_lstpr_char_en.c \
				ft_lstpr_char.c \
				ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c\
				ft_lutoa.c \
				ft_number_len.c \
				ft_stradd.c \
				ft_strcpy.c \
				ft_end.c \
				ft_revstr.c \
				ft_utils.c  \
				ft_fprintf.c \
				ft_call_types.c \
				ft_flags_handl.c \
				ft_shit_printing.c \
				ft_printing_utils.c \
				ft_call_types_utils.c \
				get_next_line.c \
				ft_valid_f.c \
				ft_tablen.c \
				ft_pr_tab.c \
				ft_atof.c \
				ft_strcmp.c \
				ft_linelen.c \
				ft_free_tab.c \
				flip_bit.c \
				standered_error.c \
				ft_lstdel_index.c \
				bitwise_op.c \

OBJECT_FILES = $(SRC_FILES:.c=.o)
OBJECT_FILES := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))

.PHONY = all bonus clean fclean re

$(NAME): $(OBJECT_FILES)
	@ar rcs $(NAME) $(OBJECT_FILES)
	@echo
	@echo  "library created $(GREEN){OK}$(RESET)"

$(OBJECT_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@(mkdir $(OBJECT_FOLDER) 2> /dev/null && echo "creating libft "$(OBJECT_FOLDER)" folder $(GREEN){OK}$(RESET)") || true
	@gcc $(FLAGS) -I $(HEADERS)  -o $@ -c $< && (echo  "creating" $< "object $(GREEN){OK}$(RESET)")

all: $(NAME)

clean:
	@(rm $(OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FILES)) || true
	@(rm -r  $(OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FOLDER)) || true

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)) || true


re: fclean $(NAME)

everything: all clean
