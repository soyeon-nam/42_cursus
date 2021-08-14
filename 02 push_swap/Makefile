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
# NAME		=	a.out

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror 


AR			=	ar
ARFLAGS		=	-rcs
RM			=	rm -rf

# LIBRARY ARCHIVE
LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# HEADERS
HEADERS_DIRECTORY = ./inc/

# SOURCES
SRCS		=	./scrs/a_to_b.c\
				./scrs/b_to_a.c\
				./scrs/do_multiple_op.c\
				./scrs/do_op_app.c\
				./scrs/do_op.c\
				./scrs/set_pivot.c\
				./scrs/ft_atoi_ps.c\
				./scrs/main.c\
				./scrs/arrange_stack.c\
				./scrs/quick_sort.c\
				./scrs/sort_under_six.c\
				./scrs/terminate.c\
				./scrs/conquer_a.c\
				./scrs/conquer_b.c\

# OBJECTS
OBJS		= $(SRCS:.c=.o)

# # BONUS SOURCES
# BSRCS	=	

# # BONUS OBJECTS
# BOBJS	=	$(BSRCS:.c=.o)

# COLOR FLAGS
FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

ifdef FLAG_BONUS
	TARGET = $(BNAME)
else
	TARGET = $(NAME)
endif

all: $(LIB_NAME) $(NAME)

bonus :
	@make FLAG_BONUS=1 all

$(LIB_NAME) :
	@make -C $(LIB_DIR)
	@printf "${FG_GREEN}Libft make all succeeded!\n${NO_COLOR}"

$(NAME): $(SRCS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@
	@printf "${FG_GREEN}Projcet make all succeeded!\n${NO_COLOR}"

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
