# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arraji <arraji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/18 16:04:41 by arraji            #+#    #+#              #
#    Updated: 2021/04/05 14:56:22 by arraji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Wextra -Werror
SRC_FOLDER = ./srcs
HEADER_FOLDER = ./includes
LIBFT_HEADER = ./libft/includes
LIBFT_FOLDER = ./libft
OBJECT_FOLDER = ./objects
LIBS = -ltermcap
LIBFT_LIB = libft.a
RED = \033[0;31m
GREEN = \033[0;32m
GOLD = \033[0;33m
RESET = \033[0m

SRC_FILES =  main.c \
signals.c \
builtins.c \
executing.c \
need.c \
pre_execute.c \
env_handle.c \
parser_needs.c \
file_expansion.c \
variables_expansion.c \
sets.c \
error.c \
lexer.c \
parser.c \
here_we_go.c \
export_need.c \
history.c \
history_need.c \
builtins2.c \
sets2.c \

OBJECT_FILES = $(SRC_FILES:.c=.o)
OBJECT_FILES := $(addprefix $(OBJECT_FOLDER)/, $(OBJECT_FILES))
LIBFT_FILE := $(LIBFT_FOLDER)/$(LIBFT_LIB)

.PHONY = all bonus clean fclean re credit

all: credit $(NAME)

LIB_RULE:
	@make -C $(LIBFT_FOLDER)/

$(NAME): LIB_RULE $(OBJECT_FILES)
	@clang -g -I $(HEADER_FOLDER) -I $(LIBFT_FOLDER)  $(OBJECT_FILES) $(LIBFT_FOLDER)/$(LIBFT_LIB) $(LIBS) -o $@
	@echo
	@echo $(NAME)" created $(GREEN)successfully$(RESET)"

$(OBJECT_FOLDER)/%.o: $(SRC_FOLDER)/%.c $(HEADER_FOLDER)/*.h
	@(mkdir $(OBJECT_FOLDER) 2> /dev/null && echo "creating "$(OBJECT_FOLDER)" folder $(GREEN){OK}$(RESET)") || true
	@clang $(FLAGS) -g -I $(HEADER_FOLDER) -I $(LIBFT_HEADER) -D PS='"$(NAME)$$> "' -o $@ -c $< && echo "creating" $< "object $(GREEN){OK}$(RESET)"

clean:
	@(rm $(OBJECT_FILES) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FILES)) || true
	@(rm -r $(OBJECT_FOLDER) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(OBJECT_FOLDER)) || true
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@(rm $(NAME) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(NAME)) || true
	@(rm $(LIBFT_FOLDER)/$(LIBFT_LIB) 2> /dev/null && echo "$(RED)deleting$(RESET): " $(LIBFT_LIB)) || true

re: fclean $(NAME)

credit:
	@printf "					$(RED)_$(NAME) made by:_$(RESET)\n"
	@echo "███████╗ ██████╗████████╗ █████╗ ██████╗  █████╗  ██████╗ ██████╗ █████╗"
	@echo "██╔════╝██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██╔══██╗"
	@echo "█████╗  ╚█████╗    ██║   ███████║██████╔╝██║  ██║╚█████╗ ╚█████╗ ███████║"
	@echo "██╔══╝   ╚═══██╗   ██║   ██╔══██║██╔══██╗██║  ██║ ╚═══██╗ ╚═══██╗██╔══██║"
	@echo "███████╗██████╔╝   ██║   ██║  ██║██║  ██║╚█████╔╝██████╔╝██████╔╝██║  ██║"
	@echo "╚══════╝╚═════╝    ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═╝"
