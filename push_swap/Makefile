# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 09:29:39 by cedmulle          #+#    #+#              #
#    Updated: 2023/11/16 16:39:46 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                 Variables                                    #
# ---------------------------------------------------------------------------- #
NAME		= push_swap
INC			= inc/
SRC_DIR		= srcs/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
SRCS		= $(SRC_DIR)move_push.c \
				$(SRC_DIR)move_rev_rotate.c \
				$(SRC_DIR)move_rotate.c \
				$(SRC_DIR)sort_stacks.c \
				$(SRC_DIR)sort_3.c \
				$(SRC_DIR)move_swap.c \
				$(SRC_DIR)errors.c \
				$(SRC_DIR)a_initializer.c \
				$(SRC_DIR)b_initializer.c \
				$(SRC_DIR)main.c \
				$(SRC_DIR)ft_split.c \
				$(SRC_DIR)stack_init.c \
				$(SRC_DIR)stack_utils.c
OBJ 		= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
# ---------------------------------------------------------------------------- #
#                                 Fonctions                                    #
# ---------------------------------------------------------------------------- #
all: 			$(NAME)

$(NAME): 		$(OBJ)
				@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)
				@echo "\033[1;36m--------------------------\033[0m"
				@echo "\033[1;36m√ Compilation successful √\033[0m"
				@echo "\033[1;36m--------------------------\033[0m"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@echo "\033[1;35m--------------------------\033[0m"
				@echo "\033[1;35m√ Objects files deleted √\033[0m"

fclean: 		clean
				@$(RM) $(NAME)
				@echo "\033[1;35m√ The ${NAME} deleted √\033[0m"
				@echo "\033[1;35m--------------------------\033[0m"

re: 			fclean all

.PHONY: 		start all clean fclean re
