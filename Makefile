# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmncube <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 12:32:02 by nmncube           #+#    #+#              #
#    Updated: 2019/06/28 14:45:35 by nmncube          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run

SRC  = get_next_line.c main.c

LIB = libft/libft.a

FLAGS = -Wall -Werror -Wextra -o

all: $(NAME)
	
$(NAME): $(LIB)
		gcc $(FLAGS) $(NAME) $(SRC) $(LIB)

$(LIB):
		make re -C libft
		
clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
