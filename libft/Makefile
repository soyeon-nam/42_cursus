NAME = bsq

SRC = srcs/main.c 

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -O3 -o $(NAME) $(SRC)

clean:
		/bin/rm -f

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all