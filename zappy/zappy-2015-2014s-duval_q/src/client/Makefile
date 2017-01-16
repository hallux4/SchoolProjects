SRC_DIR=	src
OBJ_DIR=	obj
INC_DIR=	include

NAME=		client

SRCS=		main.cpp \
		player/Player.cpp \
		player/PlayerData.cpp \
		network/Socket.cpp \
		parse/ConsumerParser.cpp \
		parse/ParserZappyClient.cpp \
		parse/ProducterStream.cpp \
		parse/Request.cpp

OBJ=		$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

CC=		g++

RM=		rm -f

CFLAGS +=	-Werror -Wextra -Wall -g
CFLAGS +=	-I $(INC_DIR)

all:		$(NAME)

$(NAME):      $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

re:		fclean all

.PHONY: 	clean fclean all re