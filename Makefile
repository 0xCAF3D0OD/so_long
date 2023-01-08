# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:43:13 by kdi-noce          #+#    #+#              #
#    Updated: 2022/02/25 19:08:59 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
LIB1 	= printf/libftprintf.a
LIB2 	= libft/libft.a
CC 		= gcc
#CFLAG 	= -Wall -Werror -Wextra -g3
OPTION 	= -c
SRC		= 	so_long_anx.c\
			so_long.c\
			so_long_map.c\
			so_long_exit.c\
			so_long_error.c\
			check_ber.c
OBJ 	= $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAG) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./mlx
		make -C ./libft
		$(CC) -fsanitize=address $(OBJ) $(LIB2) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

libft.a: libft/
			make -C libft
clean:
		/bin/rm -rf $(OBJ)
		make -C libft clean
fclean: clean
		/bin/rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re all

