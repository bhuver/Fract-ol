#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhuver <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/17 13:39:58 by bhuver            #+#    #+#              #
#    Updated: 2016/10/05 16:34:13 by bhuver           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
SRC  = 	main.c			\
		core.c			\
		tracing.c		\
		color.c			\
		fractals.c		\
		zoom.c			\

OBJ = $(SRC:.c=.o)
FLAGS =  -Wall -Wextra -Werror
INCLUDE = libft/includes

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c -I $(INCLUDE) $(SRC)
		@gcc $(FLAGS) -o $(NAME) ./libft/libft.a $(OBJ) -lmlx -framework OpenGL -framework AppKit
		@echo "Compilation successful."
clean:
		@rm -rf $(OBJ)
		@echo "Cleaned objects."
fclean: clean
		@rm -rf $(NAME)
		@echo "Cleaned exe."
re: fclean all

.PHONY: clean fclean re
