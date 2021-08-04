# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snam <snam@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 03:05:48 by snam              #+#    #+#              #
#    Updated: 2021/08/05 03:05:49 by snam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADERS_DIRECTORY = ./inc/

SRCS = ./scrs/a_to_b.c\
		./scrs/b_to_a.c\
		./scrs/do_multiple_op.c\
		./scrs/do_op_app.c\
		./scrs/do_op.c\
		./scrs/set_pivot.c\
		./scrs/ft_atoi_ps.c\
		./scrs/ft_split.c\
		./scrs/ft_strcmp.c\
		./scrs/main.c\
		./scrs/parse.c\
		./scrs/push_swap.c\
		./scrs/quick_sort.c\
		./scrs/sort_under_six.c\
		./scrs/terminate.c\
		./scrs/divide_a.c\
		./scrs/divide_b.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re



