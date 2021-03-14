# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 17:09:25 by jjaouen           #+#    #+#              #
#    Updated: 2017/06/06 00:53:21 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCF = gcc -Wall -Werror -Wextra

NAME = libft.a

HEAD = libft.h

DEP = ./Makefile ./includes/libft.h

CC = gcc
NAME = libft.a
FLAGS += -Wall -Wextra -Werror

SRC_DIR 	= src/
HEADERS 	= ./includes

SRC = $(SRC_DIR)ft_memset.c \
	$(SRC_DIR)ft_free_gnl.c \
	$(SRC_DIR)ft_strcapitalizer.c \
	$(SRC_DIR)ft_strtrim_all.c \
	$(SRC_DIR)ft_free_words_tables.c \
	$(SRC_DIR)ft_tablen.c \
	$(SRC_DIR)ft_atoi_long.c \
	$(SRC_DIR)ft_memallocexit.c \
	$(SRC_DIR)ft_replace_char.c \
	$(SRC_DIR)ft_atoi_imt.c \
	$(SRC_DIR)ft_move_char_right.c \
	$(SRC_DIR)get_next_line.c \
	$(SRC_DIR)ft_itoa_base.c \
	$(SRC_DIR)ft_itoa_base_imt.c \
	$(SRC_DIR)ft_itoa_base_uimt.c \
	$(SRC_DIR)ft_itoa_imt.c \
	$(SRC_DIR)ft_itoa_uimt.c \
	$(SRC_DIR)ft_atoi_base.c \
	$(SRC_DIR)ft_strsubf.c \
	$(SRC_DIR)ft_strjoinf.c \
	$(SRC_DIR)ft_strchrint.c \
	$(SRC_DIR)ft_lstadd_end.c \
	$(SRC_DIR)ft_bzero.c \
	$(SRC_DIR)ft_memcpy.c \
	$(SRC_DIR)ft_memchr.c \
	$(SRC_DIR)ft_memccpy.c \
	$(SRC_DIR)ft_memmove.c \
	$(SRC_DIR)ft_memcmp.c \
	$(SRC_DIR)ft_strlen.c \
	$(SRC_DIR)ft_strdup.c \
	$(SRC_DIR)ft_strcpy.c \
	$(SRC_DIR)ft_strncpy.c \
	$(SRC_DIR)ft_strcat.c \
	$(SRC_DIR)ft_strncat.c \
	$(SRC_DIR)ft_strlcat.c \
	$(SRC_DIR)ft_strchr.c \
	$(SRC_DIR)ft_strrchr.c \
	$(SRC_DIR)ft_strstr.c \
	$(SRC_DIR)ft_strnstr.c \
	$(SRC_DIR)ft_strcmp.c \
	$(SRC_DIR)ft_strncmp.c \
	$(SRC_DIR)ft_atoi.c \
	$(SRC_DIR)ft_isalpha.c \
	$(SRC_DIR)ft_isdigit.c \
	$(SRC_DIR)ft_isalnum.c \
	$(SRC_DIR)ft_isascii.c \
	$(SRC_DIR)ft_isprint.c \
	$(SRC_DIR)ft_toupper.c \
	$(SRC_DIR)ft_tolower.c \
	$(SRC_DIR)ft_memalloc.c \
	$(SRC_DIR)ft_memdel.c \
	$(SRC_DIR)ft_strnew.c \
	$(SRC_DIR)ft_strdel.c \
	$(SRC_DIR)ft_strclr.c \
	$(SRC_DIR)ft_striter.c \
	$(SRC_DIR)ft_striteri.c \
	$(SRC_DIR)ft_strmap.c \
	$(SRC_DIR)ft_strmapi.c \
	$(SRC_DIR)ft_strequ.c \
	$(SRC_DIR)ft_strnequ.c \
	$(SRC_DIR)ft_strsub.c \
	$(SRC_DIR)ft_strjoin.c \
	$(SRC_DIR)ft_strtrim.c \
	$(SRC_DIR)ft_strsplit.c \
	$(SRC_DIR)ft_itoa.c \
	$(SRC_DIR)ft_putchar.c \
	$(SRC_DIR)ft_putstr.c \
	$(SRC_DIR)ft_putendl.c \
	$(SRC_DIR)ft_putnbr.c \
	$(SRC_DIR)ft_putchar_fd.c \
	$(SRC_DIR)ft_putstr_fd.c \
	$(SRC_DIR)ft_putendl_fd.c \
	$(SRC_DIR)ft_putnbr_fd.c \
	$(SRC_DIR)ft_lstnew.c \
	$(SRC_DIR)ft_lstdelone.c \
	$(SRC_DIR)ft_lstdel.c \
	$(SRC_DIR)ft_lstadd.c \
	$(SRC_DIR)ft_lstiter.c \
	$(SRC_DIR)ft_lstmap.c \
	$(SRC_DIR)ft_swap.c \
	$(SRC_DIR)ft_range.c \
	$(SRC_DIR)ft_is_sort.c \
	$(SRC_DIR)ft_count_if.c \
	$(SRC_DIR)ft_strmaj.c \
	$(SRC_DIR)ft_count_list.c \
	$(SRC_DIR)ft_sqrt.c \
	$(SRC_DIR)ft_print_words_tables.c

OBJ += $(SRC:.c=.o)

BUILD_PRINT = @echo "\r\033[38;5;214m[LIBFT] \033[38;5;208mBuilding $<"
DONE = @echo "\033[K\033[1;38;5;226mLIBFT done!\e[0m"
CLEAN_O = @echo "\033[38;5;246mObject files removed! [LIBFT]\e[0m"
CLEAN_A = @echo "\033[38;5;246mExecutable removed! [LIBFT]\e[0m"


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