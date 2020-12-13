NAME = run.a

SRC = get_next_line.c main.c

LIB = libft/libft.a

FLAGS = -o

all: $(NAME)

$(NAME): $(LIB)
		gcc $(FLAGS) $(NAME) $(SRC) $(LIB)
		rm -f a.out
$(LIB):
	make re -C libft
clean:
	rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all
