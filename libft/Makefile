# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfoulon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 09:29:04 by wfoulon           #+#    #+#              #
#    Updated: 2017/11/10 10:51:12 by wfoulon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	libft.a

SRC 			= 	SRCS/ft_memset.c \
					SRCS/ft_bzero.c \
					SRCS/ft_memcpy.c \
					SRCS/ft_memccpy.c \
					SRCS/ft_memmove.c \
					SRCS/ft_memchr.c \
					SRCS/ft_memcmp.c \
					SRCS/ft_strlen.c \
					SRCS/ft_strdup.c \
					SRCS/ft_strcpy.c \
					SRCS/ft_strncpy.c \
					SRCS/ft_strcat.c \
					SRCS/ft_strncat.c \
					SRCS/ft_strlcat.c \
					SRCS/ft_strchr.c \
					SRCS/ft_strrchr.c \
					SRCS/ft_strstr.c \
					SRCS/ft_strnstr.c \
					SRCS/ft_strcmp.c \
					SRCS/ft_strncmp.c \
					SRCS/ft_atoi.c \
					SRCS/ft_isalpha.c \
					SRCS/ft_isdigit.c \
					SRCS/ft_isalnum.c \
					SRCS/ft_isascii.c \
					SRCS/ft_isprint.c \
					SRCS/ft_toupper.c \
					SRCS/ft_tolower.c \
					SRCS/ft_memalloc.c \
					SRCS/ft_memdel.c \
					SRCS/ft_strnew.c \
					SRCS/ft_strdel.c \
					SRCS/ft_strclr.c \
					SRCS/ft_striter.c \
					SRCS/ft_striteri.c \
					SRCS/ft_strmap.c \
					SRCS/ft_strmapi.c \
					SRCS/ft_strequ.c \
					SRCS/ft_strnequ.c \
					SRCS/ft_strsub.c \
					SRCS/ft_strjoin.c \
					SRCS/ft_strtrim.c \
					SRCS/ft_putchar.c \
					SRCS/ft_putstr.c \
					SRCS/ft_putendl.c \
					SRCS/ft_putnbr.c \
					SRCS/ft_putchar_fd.c \
					SRCS/ft_putstr_fd.c \
					SRCS/ft_putendl_fd.c \
					SRCS/ft_putnbr_fd.c \
					SRCS/ft_itoa.c \
					SRCS/ft_strsplit.c \
					SRCS/ft_isspace.c \
					SRCS/ft_swap.c \
					SRCS/ft_strrev.c \
					SRCS/ft_power.c \
					SRCS/ft_factorial.c \
					SRCS/ft_lstnew.c \
					SRCS/ft_lstadd.c \
					SRCS/ft_lstiter.c \
					SRCS/ft_lstmap.c \
					SRCS/ft_lstdel.c \
					SRCS/ft_lstdelone.c \
					SRCS/get_next_line.c \
					SRCS/ft_atoi_base.c \
					SRCS/ft_free_tab.c \
					SRCS/ft_hexa_to_int.c \
					SRCS/ft_is_number.c \
					SRCS/ft_is_present.c \
					SRCS/ft_realloc.c \
					SRCS/ft_split_len.c \
					SRCS/ft_atoiletters.c \

OBJ =	$(SRC:.c=.o)

INC	=	includes/

FLAGS =	-Wall -Werror -Wextra

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc $(FLAGS) -o $@ -c $< -I $(INC)


$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;1mlibft is ready\033[0m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[37mall files.o are removed\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m$(NAME) is deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re