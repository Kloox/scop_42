# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 17:09:25 by jjaouen           #+#    #+#              #
#    Updated: 2017/06/06 00:53:21 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = glmft.a
FLAGS += -Wall -Wextra -Werror

SRC_DIR 	= src/
HEADERS 	= ./includes

DEP = ./Makefile ./includes/glmft.h


SRC = $(SRC_DIR)vec3.c \
	  $(SRC_DIR)mat4.c \
	  ${SRC_DIR}utils.c \
	  ${SRC_DIR}mat4_transform.c \
	  ${SRC_DIR}mat4_rotation.c

OBJ += $(SRC:.c=.o)

BUILD_PRINT = @echo "\r\033[38;5;214m[GLMFT] \033[38;5;208mBuilding $<"
DONE = @echo "\033[K\033[1;38;5;226mGLMFT done!\e[0m"
CLEAN_O = @echo "\033[38;5;246mObject files removed! [GLMFT]\e[0m"
CLEAN_A = @echo "\033[38;5;246mExecutable removed! [GLMFT]\e[0m"


all: $(DEP) $(NAME)

$(OBJ): %.o: %.c
	$(BUILD_PRINT)
	@gcc $(FLAGS) -I $(HEADERS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(DONE)

clean:
	@/bin/rm -rf $(OBJ)
	$(CLEAN_O)

fclean: clean
	@/bin/rm -rf $(NAME)
	$(CLEAN_A)

re: fclean all

.PHONY: all clean fclean re