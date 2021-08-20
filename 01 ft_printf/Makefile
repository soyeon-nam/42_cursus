# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snam <snam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 23:03:28 by snam              #+#    #+#              #
#    Updated: 2021/06/13 10:25:11 by snam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
HEADER		=	ft_printf.h
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f

INC			=	./inc

SRCS_DIR	=	./srcs/
SRCS_LST 	=	ft_printf.c\
				state_machine.c\
				process.c\
				create_cppc.c \
				create_diux.c\
				create_s.c\
				set_print_info.c\
				count_digit.c\
				print_functions.c\
				update_nbr.c
				
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c  $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
