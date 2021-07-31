NAME = push_swap
INCLUDES = -I$(HEADERS_DIRECTORY)
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADERS_DIRECTORY = ./inc/

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c  $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re