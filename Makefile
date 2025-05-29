# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 07:13:14 by elakhfif          #+#    #+#              #
#    Updated: 2024/06/11 07:44:36 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -Wformat=2  -flto -ffast-math -pedantic -Wunreachable-code -Wfloat-equal -Warray-bounds -O3

OS := $(shell uname -s)

USER := $(shell whoami)

ifeq ($(OS), Linux)
	 MLX_FLAGS = -lmlx42 -ldl -lglfw -pthread -lm
else
	 MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
	 LIB_DIR = ./includes/MLX42/libmlx42.a
	 GLFW_DIR = ./includes/MLX42/libglfw3.a
	INC_DIR = -I$(HOME)/lib/include/ 
endif

CC = cc

NAME = cub3D

LIBFT = lib/libft.a

OBJ = build/parser.o build/main.o build/checker.o build/check_map.o \
      build/check_player.o build/extract_assets.o build/read_map.o build/textures.o\
      build/parser_utils.o build/init_screen.o build/init_game.o build/render.o \
      build/raycast.o build/player_moves.o build/realcast.o\

SRC = src/parsing/parser.c src/parsing/checker.c src/parsing/check_map.c\
	src/parsing/check_player.c src/parsing/extract_assets.c src/parsing/textures.c\
	src/parsing/main.c src/parsing/read_map.c src/parsing/parser_utils.c \
	src/raycasting/init_screen.c src/raycasting/init_game.c src/raycasting/render.c\
	src/raycasting/raycast.c src/raycasting/player_moves.c src/raycasting/realcast.c\

INCLUDES = lib/

all: build $(NAME)

build/%.o: src/*/%.c
	$(CC) -I$(INCLUDES) $(INC_DIR) $< $(CFLAGS) -c -o $@

build:
	if [ ! -d "build/" ]; then \
		mkdir build; \
	fi

$(LIBFT):
	$(MAKE) -C lib/

$(NAME): $(OBJ) $(GNL_SRC) $(LIBFT) $(INCLUDES)
	$(CC) $(CFLAGS) $(LIB_DIR) $(OBJ) $(GLFW_DIR) $(MLX_FLAGS) -I$(INCLUDES) $(INC_DIR) $(LIBFT) $(GNL_SRC) -o $(NAME)

clean :
	$(MAKE) fclean -C lib/
	rm -rf build/
	rm -rf cub3d.dSYM

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.SILENT: all clean fclean re build
