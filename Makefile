# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luntiet- <luntiet-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 00:44:35 by luntiet-          #+#    #+#              #
#    Updated: 2023/01/09 16:16:13 by luntiet-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex
SRC_DIR = src
SRC_BONUS_DIR = src_bonus
OBJ_DIR = obj
OBJ_BONUS_DIR = obj_bonus
DIR_DUP = mkdir -p $(@D)

SRC = main.c \
		input.c \
		utils.c \
		error.c \
		pipex.c

SRC_BONUS = main_bonus.c \
				input_bonus.c \
				utils_bonus.c \
				error_bonus.c \
				pipex_bonus.c

SRC := $(SRC:%=$(SRC_DIR)/%)
SRC_BONUS := $(SRC_BONUS:%=$(SRC_BONUS_DIR)/%)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
LIBFT = ./libft/libft.a

all: $(NAME)

bonus: $(OBJ_BONUS)
	@$(CC) $(LINK_FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LINK_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<


$(LIBFT):
	@git submodule init
	@git submodule update
	@cd libft && make && make clean

clean:
	@rm -rf $(OBJ) $(OBJ_DIR) $(OBJ_BONUS) $(OBJ_BONUS_DIR)

clo:
	rm -f outfile

fclean: clean
	@rm -rf $(NAME)

libclean:
	@rm -rf ./libft
	@rm -rf ./MLX42

re: fclean all

.PHONY: all clean fclean re
