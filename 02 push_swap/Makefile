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

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	CFLAGS = -Wall -Wextra -Werror 

AR			=	ar
ARFLAGS		=	-rcs
RM			=	rm -rf

LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))

SRCS 		=	./scrs/a_to_b.c\
				./scrs/b_to_a.c\
				./scrs/do_multiple_op.c\
				./scrs/do_op_app.c\
				./scrs/do_op.c\
				./scrs/set_pivot.c\
				./scrs/ft_atoi_ps.c\
				./scrs/main.c\
				./scrs/parse.c\
				./scrs/push_swap.c\
				./scrs/quick_sort.c\
				./scrs/sort_under_six.c\
				./scrs/terminate.c\
				./scrs/conquer_a.c\
				./scrs/conquer_b.c\

OBJS 		=	$(SRCS:.c=.o)

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	make -C $(LIB_DIR)

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
