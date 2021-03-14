# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/23 05:45:53 by jjaouen           #+#    #+#              #
#    Updated: 2020/06/23 05:45:53 by jjaouen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop
GCCF = gcc -Wall -Werror -Wextra
ICON_PATH=./Contents/Resources/icon/scop.ico
GREEN       = \033[32m
RED         = \033[31m
DEFAULT     = \033[37m
PATHOBJ = obj/
PATHSRC = src/
GLAD_PATH = ./Contents/Resources/glad
GLAD_SRC = ../$(GLAD_PATH)/src/glad.c
GLAD_INCLUDE = $(GLAD_PATH)/include/
DEP = Makefile src/includes/scop.h
SRC = scop.c \
	  parsing.c \
	  parsing_v.c \
	  parsing_vt.c \
	  parsing_f.c \
	  shaders.c \
	  parsing_f_second.c \
	  vertices.c \
	  uniforms.c \
	  utils_uniforms.c \
	  hooks.c \
	  cam_hooks.c \
	  graphic_hooks.c \
	  utils_entry.c \
	  entry.c \
	  utils.c \
	  utils_glfw.c \
	  callbacks.c \
	  file.c \
	  render.c \
	  build.c \
	  $(GLAD_SRC)
HEAD = -I ./src/includes/ -I libft/includes/ -I ./glmft/includes/ -I $(GLAD_INCLUDE)
LIBFT = ./libft/libft.a
GLMFT = ./glmft/glmft.a
OBJ = $(patsubst %.c,$(PATHOBJ)/%.o,$(SRC))

GLFW_PATH=./Contents/Resources/GLFW-3.3.2

OPEN_GL_VERSION=4.6

FLGGRAPH_WINDOWS = -lglfw3dll -lopengl32
FLGGRAPH_UBUNTU = -lGL -lglfw3 -lX11 -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lm
FLGGRAPH_MACOS = -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

ifeq ($(OS),Windows_NT)
    COMPIL_CMD = $(GCCF) $(OBJ) $(GRAPH_LIB) $(LIBFT) $(GLMFT) -o $(NAME) $(FLGGRAPH_WINDOWS); ResourceHacker -open $(NAME).exe -save $(NAME).exe -action addskip -res $(ICON_PATH) -mask ICONGROUP,MAIN,
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
    	COMPIL_CMD = $(GCCF) $(OBJ) $(GRAPH_LIB) $(LIBFT) $(GLMFT) -o $(NAME) $(FLGGRAPH_UBUNTU)
    endif
    ifeq ($(UNAME_S),Darwin)
    	COMPIL_CMD = $(GCCF) $(OBJ) $(GRAPH_LIB) $(LIBFT) $(GLMFT) -o $(NAME) $(FLGGRAPH_MACOS)
    endif
endif

ifeq ($(shell uname),Darwin)
    ECHO    = echo
else
	ECHO    = echo
endif

all: $(NAME)

libft: $(LIBFT)
glmft: $(GLMFT)

$(PATHOBJ):
	@mkdir -p obj

$(LIBFT):
	@make -C ./libft/

$(GLMFT):
	@make -C ./glmft/

$(NAME): $(DEP) $(LIBFT) $(GLMFT) $(addprefix $(PATHSRC)/,$(SRC)) $(PATHOBJ) $(OBJ)
	@$(ECHO) "\r$(GREEN) The .o from $(NAME) are compiled.$(DEFAULT)"
	@$(ECHO) "GCC command used : $(COMPIL_CMD)"
	@$(COMPIL_CMD)
	@$(ECHO) "$(GREEN)$(NAME)$(DEFAULT) created."

$(PATHOBJ)/%.o: $(PATHSRC)/%.c
	@$(ECHO) "\r$(GREEN) Compiling $@                      \c\033[K"
	@$(GCCF) -c $< -o $@ $(HEAD)

clean:
	@$(ECHO) "All $(RED).o$(DEFAULT) are now deleted for $(NAME)."
	@make clean -C ./libft/
	@make clean -C ./glmft/
	@rm -rf $(PATHOBJ)

fclean: clean
	@$(ECHO) "$(RED)$(NAME)$(DEFAULT) is now deleted."
	@make fclean -C ./libft/
	@make fclean -C ./glmft/
	@rm -rf $(NAME)

re: fclean all

install_glfw:
	wget https://github.com/glfw/glfw/releases/download/3.3.2/glfw-3.3.2.zip -O $(GLFW_PATH).zip
	unzip $(GLFW_PATH).zip -d $(GLFW_PATH)
	cd $(GLFW_PATH)/glfw-3.3.2 ;cmake .;make;sudo make install;

.PHONY: all clean fclean re
