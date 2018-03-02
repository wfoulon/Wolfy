# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfoulon <wfoulon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 12:21:46 by wfoulon           #+#    #+#              #
#    Updated: 2018/02/28 12:22:20 by wfoulon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = srcs/config/settings.c \
		srcs/keyevents/keyevents.c \
		srcs/sdl/sdl_init.c \
		srcs/main.c \
		srcs/tools/ft_tools.c \
		srcs/raycasting/raycasting.c \
		srcs/ui/cursor.c \
		srcs/tools/parser.c \
		srcs/sdl/ft_pixel.c \
		srcs/audio/audio.c \
		srcs/ui/minimap.c \
		srcs/menu/menu.c \
		srcs/ui/weapon.c \
		srcs/audio/soundeffects.c \
		srcs/keyevents/mouseevents.c \
		srcs/raycasting/sdlthread.c \
		srcs/raycasting/floorcasting.c \
		srcs/raycasting/sprites.c \
		srcs/raycasting/skycasting.c \
		srcs/sdl/sdl_init2.c

LOGIN = wfoulon

OBJ = $(SRC:%.c=obj/%.o)

HEADER = includes/wolf3d.h

INC = -I Includes

INCLFT = -I Libft/includes

INCMLX = -I mlx/mlx.h

SDL = -I SDL2/Headers/ -I/usr/local/include

LIB = -L Libft/ -lft -L/usr/local/lib

FLAGS = -Wall -Werror -Wextra

FRAME = -framework OpenCl -framework Appkit

OBJ_DIR = obj

#SDL_LIB = -framework SDL2 -I SDL2/Headers/

SDL_DIR		=	SDL2-2.0.7
SDL_LIB		=	$(SDL_DIR)/build/.libs/libSDL2.a
SDL_INC		=	$(SDL_DIR)/include/
FLAG_SDL	=	-I/$(SDL_INC) $(SDL_LIB) -framework Cocoa -framework CoreAudio -framework AudioToolbox -framework ForceFeedback -framework CoreVideo -framework Carbon -framework IOKit -liconv

.SILENT :

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

debug: FLAGS += -g
debug: $(NAME)

$(OBJ): obj/%.o: %.c $(HEADER)
		gcc $(INC) $(FLAGS) -c $< -o $@ $(INCLFT) -I $(SDL_INC)

dep:
	make -C Libft/
	echo "\033[3;1m Creating $(NAME)\033[0m"
	mkdir -p $(OBJ_DIR)/srcs/Menu
	mkdir -p $(OBJ_DIR)/srcs/audio
	mkdir -p $(OBJ_DIR)/srcs/keyevents
	mkdir -p $(OBJ_DIR)/srcs/tools
	mkdir -p $(OBJ_DIR)/srcs/raycasting
	mkdir -p $(OBJ_DIR)/srcs/ui
	mkdir -p $(OBJ_DIR)/srcs/config
	mkdir -p $(OBJ_DIR)/srcs/sdl

noflag: FLAGS = -g
noflag: $(NAME)
$(NAME): dep $(OBJ)
		#tar xzf .SDL2-2.0.5.tar.gz
		gcc -o $(NAME) $(OBJ) $(LIB) $(FLAG_SDL) $(SDL_LIB)
		@echo "\033[38;5;79m  [$(NAME)]	Compiled."
		@echo "\033[34m"
		@echo "\033[38;5;84m  MMMºººAMV '7MMºººYb.   '7MMºººMq. "
		@echo "  M'   AMV    MM    'Yb.   MM   'MM."
		@echo "\033[38;5;85m  '   AMV     MM     'Mb   MM   ,M9 "
		@echo "     AMV      MM      MM   MMmmdM9  "
		@echo "\033[38;5;86m    AMV   ,   MM     ,MP   MM"
		@echo "   AMV   ,M   MM    ,dP'   MM"
		@echo "\033[38;5;87m  AMVmmmmMM .JMMmmmdP'   .JMML. "
		@echo ""
		@echo "\033[38;5;7m [2018]                    [${LOGIN}]"
		@echo ""
		echo " \033[35;1m\n $(NAME) is ready\033[0m"

norme: clean
		norminette include/
		norminette srcs/
		norminette libft/includes/
		norminette libft/SRCS/

clean:
		make -C Libft/ clean
		/bin/rm -rf ./OBJ
		rm -f $(OBJ)
		echo " \033[31mall unexpected files and .o are removed\033[0m"

fclean: clean
		make -C Libft/ fclean
		/bin/rm -f $(NAME)
		echo " \033[34m$(NAME) && libft.a are removed\033[0m"

re: fclean all

.PHONY: all clean fclean re 
