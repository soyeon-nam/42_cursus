SERVER		=	server
CLIENT		=	client

CC			=	gcc
# CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g -fsanitize=address
CFLAGS		=	-g

AR			=	ar
ARFLAGS		=	-rcs
RM			=	rm -rf

# COLOR FLAGS
FG_BLACK   = \e[30m
FG_RED     = \e[31m
FG_GREEN   = \e[32m
FG_YELLOW  = \e[33m
FG_LBLUE   = \e[94m
FG_MAGENTA = \e[35m
NO_COLOR   = \e[0m

# LIBRARY ARCHIVE
LIB_DIR		=	./libft/
LIB_NAME	=	libft.a
LIBS		=	$(addprefix $(LIB_DIR), $(LIB_NAME))

# HEADERS
HEADERS_DIR	=	./inc/

# SOURCES
SERVER_SCRS	=	./srcs/server.c\
				# ./inc/function.c

CLIENT_SCRS	=	./srcs/client.c\
				# ./inc/function.c

# OBJECTS
SERVER_OBJS	=	$(SERVER_SCRS:.c=.o)
CLIENT_OBJS	=	$(CLIENT_SCRS:.c=.o)


all : $(LIB_NAME) $(SERVER) $(CLIENT)

bonus : $(LIB_NAME)

$(LIB_NAME) : 
	@make -C $(LIB_DIR)
	@printf "${FG_GREEN}Libft make all succeeded!\n${NO_COLOR}"

$(SERVER) : $(SERVER_SCRS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(HEADERS_DIR)
	@printf "${FG_GREEN}Server make all succeeded!\n${NO_COLOR}"

$(CLIENT) : $(CLIENT_SCRS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(HEADERS_DIR)
	@printf "${FG_GREEN}Client make all succeeded!\n${NO_COLOR}"

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
