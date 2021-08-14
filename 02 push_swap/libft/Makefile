# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snam <snam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 20:25:46 by marvin            #+#    #+#              #
#    Updated: 2021/05/24 12:40:43 by snam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS			=	-rc
RM				=	rm -f

INCS_DIR		=	./inc

LIBFT_DIR		=	./srcs/libft
GNL_DIR			=	./srcs/get_next_line
FT_PRINTF_DIR	=	./srcs/ft_printf

LIBFT_SRCS		=	ft_strchr.c \
					ft_atoi.c \
					ft_strdup.c \
					ft_bzero.c \
					ft_strjoin.c \
					ft_calloc.c \
					ft_strlcat.c \
					ft_isalnum.c \
					ft_memccpy.c \
					ft_strlcpy.c \
					ft_isalpha.c \
					ft_memchr.c \
					ft_strlen.c \
					ft_isascii.c \
					ft_memcmp.c \
					ft_strncmp.c \
					ft_isdigit.c \
					ft_memcpy.c \
					ft_strnstr.c \
					ft_isprint.c \
					ft_memmove.c \
					ft_strrchr.c \
					ft_itoa.c	\
					ft_memset.c	\
					ft_strtrim.c \
					ft_putchar_fd.c \
					ft_substr.c \
					ft_putendl_fd.c \
					ft_tolower.c \
					ft_putnbr_fd.c \
					ft_toupper.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strcmp.c \
					ft_strmapi.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c 

GNL_SRCS		=	get_next_line.c \
					get_next_line_utils.c

FT_PRINTF_SRCS	=	update_nbr.c \
					state_machine.c \
					set_print_numbers.c \
					reset_tag.c \
					process_tocken.c \
					print_functions.c \
					print_base.c \
					ft_printf.c \
					create_x.c \
					create_u.c \
					create_spec.c \
					create_s.c \
					create_di.c \
					create_cppc.c \
					count_digit.c

all: $(NAME)

$(NAME): libft gnl

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -c $^ -o $@
	@$(AR) $(ARFLAGS) $(NAME) $@

libft: $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS:.c=.o))
ft_printf: $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRCS:.c=.o))
gnl: $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o))

clean:
	@$(RM) $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS:.c=.o))
	@$(RM) $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRCS:.c=.o))
	@$(RM) $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o))

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft gnl ft_printf
